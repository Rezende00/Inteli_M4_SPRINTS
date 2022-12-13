const express = require("express"); // para criar o servidor
const router = express.Router();  // cria o servidor

const fs = require("fs"); // altera json mais facimente: le e altera o arquivo json
const status = require("../status.json"); // importa o arquivo json

const bodyParser = require("body-parser"); // para pegar o body da requisição
const udrlencodedParser = bodyParser.urlencoded({ extended: false }); // para o express entender urlencoded

//Ganhador
router.get("/get", (req,res) => { // rota para pegar o valor da variavel winner

  const { numero } = req.body;

  if (numero == 1) {
    res.status(200).send("Jogador 1 ganhou")

  } else {
    res.status(200).send("Jogador 2 ganhou")
  }

});

router.post("/post", udrlencodedParser, (req, res) => { // rota para alterar o valor da variavel winner
  res.statusCode = 200;
  res.setHeader("Acess-Control-Allow-Origin", "*"); // permite que qualquer origem acesse a api

  status.winner = Number(req.body.winner); // pega o valor do body da requisição e coloca na variavel winner do arquivo status.json

  let data = JSON.stringify(status); // transforma o arquivo status.json em string

  fs.writeFile("status.json", data, "utf8", function (err) {
    // escreve o arquivo json com o novo valor
    if (err) {
      return console.log(err);
    }
  });

  res.json(status.winner); // retorna o valor da variavel winner
});

module.exports = router; // exporta o router para ser usado em outro arquivo
