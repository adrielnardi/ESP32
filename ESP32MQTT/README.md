# Esp32 MQTT Broker Público



### 1) Sobre

Neste projeto foi usado uma placa Esp32, conectando o seu dispositivo em um Broker MQTT público. O dispositivo faz uma simulação de um sensor de uma variável ambiente de humidade. Neste projeto não foi utilizado o sensor real, sendo enviado dados fictícios dos valores da humidade ambiente a cada 60 segundos.

### 2) Funcionamento

Foi utilizado a IDE Arduino para desenvolvimento do código, em uma placa esp32 foi conectado o seu wifi com a nossa rede local, em seguida, ela conecta no servidor público através do endereço abaixo:

```
mqtt://broker.hivemq.com:1883
```

Foi gerado uma variável random para simular a humidade (valores entre 55% a 100% ), e a cada 60 segundos, o valor gerado é enviado para o servidor público.

Detalhes do código-fonte esta disponível em [ESP32MQTT.ino](https://github.com/adrielnardi/ESP32/blob/main/ESP32MQTT/ESP32MQTT.ino)

### 3) Output
##### 3.1) Monitor Serial

Conforme a imagem abaixo, podemos ver através do monitor serial da IDE Arduino o dado sendo enviado da placa esp32 para o Broker MQTT público.

![](https://github.com/adrielnardi/ESP32/blob/main/ESP32MQTT/img/monitorSerial.PNG)

##### 3.2) HiveMQ

Conforme a imagem abaixo, podemos ver através do Dashboard os dados da umidade aparecendo no painel de mensagens. Foi preciso configurar o host, a porta(8000), subscription e o cliendID.


![](https://github.com/adrielnardi/ESP32/blob/main/ESP32MQTT/img/hiveMQTT.PNG)

### 4) Referências

- [Hivemq](https://www.hivemq.com/mqtt-cloud-broker/) 
- [PubSubClient](https://github.com/knolleary/pubsubclient)
- [Example MQTT](https://github.com/knolleary/pubsubclient/tree/master/examples/mqtt_basic)
- [IDE Arduino](https://www.arduino.cc/en/software) 

