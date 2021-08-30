# Esp32 MQTT Broker Público



### Sobre

Neste projeto foi usado uma placa Esp32, conectando o seu dispositivo em um Broker MQTT público. O dispositivo faz uma simulação de um sensor de uma variável ambiente de humidade. Neste projeto não foi utilizado o sensor real, sendo enviado dados fictícios dos valores da humidade ambiente a cada 60 segundos.

### Funcionamento

### Output
##### Monitor Serial

Conforme a imagem abaixo, podemos ver através do monitor serial da IDE Arduino o dado sendo enviado da placa esp32 para o Broker MQTT público.

[imagem]
##### HiveMQ

Conforme a imagem abaixo, podemos ver através do Dashboard os dados da umidade aparecendo no painel de mensagens.

Foi preciso configurar o host, a porta(8000), subscription e o cliendID.

[imagem]

### Referências

- [Hivemq](https://www.hivemq.com/mqtt-cloud-broker/) 
- [PubSubClient](https://github.com/knolleary/pubsubclient)
- [Example MQTT](https://github.com/knolleary/pubsubclient/tree/master/examples/mqtt_basic)

