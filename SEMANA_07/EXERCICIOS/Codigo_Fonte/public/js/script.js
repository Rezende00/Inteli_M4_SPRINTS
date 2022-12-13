$(function () {

    var anim_id; // variável para armazenar o id da animação

    //salvando alguns valores iniciais
    var container = $('#container');
    var ball = $('#ball');
    var paddle = $('.paddle');
    var paddle_1 = $('#paddle_1');
    var paddle_2 = $('#paddle_2');
    var restart_but = $('#restart_but');

    // salvando algumas declarações
    var container_width = parseInt(container.width());
    var container_height = parseInt(container.height());
    var paddle_initial_position = parseInt(paddle.css('left'));
    var paddle_width = parseInt(paddle.width());
    var ball_left = parseInt(ball.css('left'));
    var ball_height = parseInt(ball.height());
    var ball_width = parseInt(ball.width());

    // outras declarações de variáveis para uso posterior com bolinha, os paddles e o jogo.
    var go_up = false;
    var go_down = true;
    var game_over = false;

    var ball_center;
    var paddle_center;

    var ball_go = 'down';
    var ball_right_left = 'right';

    var top_angle = 6;
    var right_left_angle = 0;

    var move_right1 = false;
    var move_left1 = false;

    var move_right2 = false;
    var move_left2 = false;

    var who_won;


// -------------------------------FUNÇÃO DE INICIALIZAÇÃO--------------------------------------

    function start_game() { //função para iniciar o jogo

        if (game_over === false) {

            if (collision(ball, paddle_1)) { //colisão da bolinha com o paddle 1

                ball_center = parseInt(ball.css('left')) + ball_width / 2;
                paddle_center = parseInt(paddle_1.css('left')) + paddle_width / 2;
                ball_right_left = (ball_center > paddle_center ? 'right' : 'left');
                right_left_angle = Math.abs((paddle_center - ball_center)) / 7;
                ball_go = 'down';


            } else if (collision(ball, paddle_2)) { // colisão da bolinha com o paddle 2

                ball_center = parseInt(ball.css('left')) + ball_width / 2;
                paddle_center = parseInt(paddle_2.css('left')) + paddle_width / 2;
                ball_right_left = (ball_center > paddle_center ? 'right' : 'left');
                right_left_angle = Math.abs((paddle_center - ball_center)) / 7;
                ball_go = 'up';

            } else
            if (parseInt(ball.css('left')) <= 0) { // colisão da bolinha com a parede direita

                ball_right_left = 'right';

            } else if (parseInt(ball.css('left')) >= container_width - ball_width) { // colisão da bolinha com a parede esquerda

                ball_right_left = 'left';

            } else if (parseInt(ball.css('top')) <= 0) { // colisão da bolinha com a parede superior

                who_won = 2; // quem ganhou (jogador 2)
                player2() // função para mostrar o vencedor e chamar a função lá embaixo de enviar o resultado para o esp
                stop_the_game(); // função para parar o jogo

            } else if (parseInt(ball.css('top')) >= (container_height - ball_height)) { // colisão da bolinha com a parede inferior

                who_won = 1; // quem ganhou (jogador 1)
                player1() // função para mostrar o vencedor e chamar a função lá embaixo de enviar o resultado para o esp
                stop_the_game(); // função para parar o jogo

            }

            if (ball_go === 'down') { // movimento da bolinha
                ball_down();
            } else if (ball_go === 'up') { // movimento da bolinha
                ball_up();
            }

            anim_id = requestAnimationFrame(start_game);

        }
    }

    anim_id = requestAnimationFrame(start_game); // inicia o jogo

//-----------------------------------------CONTROLES----------------------------------------------------------------

    function left1() { //paddle 1 movimento para esquerda
        if (parseInt(paddle_1.css('left')) > 0) {
            paddle_1.css('left', parseInt(paddle_1.css('left')) - 15);
            move_left1 = requestAnimationFrame(left1);
        }
    }

    function right1() { //paddle 1 movimento para direita  
        if (parseInt(paddle_1.css('left')) < (container_width - paddle_width)) {
            paddle_1.css('left', parseInt(paddle_1.css('left')) + 15);
            move_right1 = requestAnimationFrame(right1);
        }
    }

    function left2() { //paddle 2 movimento para esquerda
        if (parseInt(paddle_2.css('left')) > 0) {
            paddle_2.css('left', parseInt(paddle_2.css('left')) - 15);
            move_left2 = requestAnimationFrame(left2);
        }
    }

    function right2() { //paddle 2 movimento para direita
        if (parseInt(paddle_2.css('left')) < (container_width - paddle_width)) {
            paddle_2.css('left', parseInt(paddle_2.css('left')) + 15);
            move_right2 = requestAnimationFrame(right2);
        }
    }

//Controles do teclado de cada jogador

    $(document).on('keydown', function (e) { //controles das teclas pressionadas
        var key = e.keyCode;
        if (key === 81 && move_left1 === false && game_over === false) {
            move_left1 = requestAnimationFrame(left1);
        } else if (key === 69 && move_right1 === false && game_over === false) {
            move_right1 = requestAnimationFrame(right1);
        } else if (key === 37 && move_left2 === false && game_over === false) {
            move_left2 = requestAnimationFrame(left2);
        } else if (key === 39 && move_right2 === false && game_over === false) {
            move_right2 = requestAnimationFrame(right2);
        }
    });


    $(document).on('keyup', function (e) { //controles das teclas soltas
        var key = e.keyCode;
        if (key === 81 && game_over === false) {
            cancelAnimationFrame(move_left1);
            move_left1 = false;
        } else if (key === 69 && game_over === false) {
            cancelAnimationFrame(move_right1);
            move_right1 = false;
        } else if (key === 37 && game_over === false) {
            cancelAnimationFrame(move_left2);
            move_left2 = false;
        } else if (key === 39 && game_over === false) {
            cancelAnimationFrame(move_right2);
            move_right2 = false;
        }
    });

//-------------------------------FUNÇÕES DE MOVIMENTO DA BOLA--------------------------------------------

    function ball_up() { // movimento da bolinha para cima e para os lados (direita e esquerda)
        ball.css('top', parseInt(ball.css('top')) - (top_angle));
        if (ball_right_left === 'left') {
            ball.css('left', parseInt(ball.css('left')) - (right_left_angle));
        } else {
            ball.css('left', parseInt(ball.css('left')) + (right_left_angle));
        }
    }

    function ball_down() { // movimento da bolinha para baixo e para os lados (direita e esquerda)
        ball.css('top', parseInt(ball.css('top')) + (top_angle));
        if (ball_right_left === 'left') {
            ball.css('left', parseInt(ball.css('left')) - (right_left_angle));
        } else {
            ball.css('left', parseInt(ball.css('left')) + (right_left_angle));
        }
    }

// -------------------------------------COLISÃO--------------------------------------------------

    function collision($div1, $div2) { // função de colisão
        var x1 = $div1.offset().left; 
        var y1 = $div1.offset().top;
        var h1 = $div1.outerHeight(true);
        var w1 = $div1.outerWidth(true);
        var b1 = y1 + h1;
        var r1 = x1 + w1;
        var x2 = $div2.offset().left;
        var y2 = $div2.offset().top;
        var h2 = $div2.outerHeight(true);
        var w2 = $div2.outerWidth(true);
        var b2 = y2 + h2;
        var r2 = x2 + w2;

        if (b1 < y2 || y1 > b2 || r1 < x2 || x1 > r2) return false; // se não houver colisão
        return true; // se houver colisão
    }

    // -------------------------------------GAME_OVER--------------------------------------------------

    function stop_the_game() { // função de game over

        cancelAnimationFrame(anim_id); // cancela a animação da bolinha
        cancelAnimationFrame(move_right1); // cancela a animação para a direita do paddle 1
        cancelAnimationFrame(move_left1); // cancela a animação para a esquerda do paddle 1
        cancelAnimationFrame(move_right2); // cancela a animação para a direita do paddle 2
        cancelAnimationFrame(move_left2); // cancela a animação para a esquerda do paddle 2
        game_over = true; 
        restart_but.html('<span><b>Jogador<b> ' + who_won + ' venceu :) </span><br><br><span id="winner">Play again</span>').show(); // mostra o botão de reiniciar o jogo
    }

    $(document).on('click', '#winner', function () { // função de reiniciar o jogo
        location.reload(); // recarrega a página
    });

});


// -------------------------FUNÇÕES PARA CONVERSAR COM OS ESP'S, EM RELAÇÃO À QUEM GANHOU--------------------------------------------------

function player1(){ // função para enviar o comando para o ESP, com o sentido do jogador 1 ganhou
    axios.get("http://192.168.125.13/win1") // endereço do ESP
}

function player2(){ // função para enviar o comando para o ESP, com o sentido do jogador 2 ganhou 
    axios.get("http://192.168.125.13/win2") // endereço do ESP
}