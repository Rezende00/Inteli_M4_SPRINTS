// para começar e rodar o código, basta rodar o comando "npm run dev" no terminal
// pois irá chamar o script "dev" que está no package.json
// que irá rodar o arquivo app.js, que é o arquivo principal do servidor
// o nodemon irá reiniciar o servidor sempre que houver alguma alteração no código (usei assim pois ficou mais fácil de desenvolver)

const bodyParser = require("body-parser"); // para pegar o body da requisição
const express = require("express"); // para criar o servidor
const app = express(); // cria o servidor

app.use(express.json()); // para o express entender json
app.use(bodyParser.urlencoded({extended:true})) // para o express entender urlencoded

app.use(express.static("public")); // para o express entender arquivos estáticos

const server = app.listen(3000, () => { // cria o servidor na porta 3000
  console.log(`Server executando at http://localhost:3000/`); 
});