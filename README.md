# Projeto-Arduino-MQTT
## Objetivo 
O objetivo do projeto MQTT+Arduino é monitorar se a porta de um rack está aberta ou fechada, através de um sensor magnético conectado ao Arduino.
Através do protocolo MQTT (Message Queuing Telemetry Transport) a mensagem é enviada pela internet para um servidor MQTT hospedado na Amazon Web Service (AWS) e é enviada para um cliente MQTT instalado em um celular com o aplicativo (MQTT Dash).

Represetanção do projeto:
![alt text](https://camo.githubusercontent.com/7beef2d4780d87a603d7de49b2da0467c8537dff96575b628a04bd4010ebb1cc/68747470733a2f2f692e696d6775722e636f6d2f4d576870586b562e706e67)

Bibliotecas:
- UIPEthernet
- PubSubClient

## Materiais 
- Arduino Uno
- Módulo Ethernet (ENC28J60)
- Sensor Magnético (MC-38)
- Jumpers

## Circuito
A representação física nos mostra que as conexões coloridas se tratam das conexões do Módulo Ethernet e as conexões brancas são as conexões do sensor magnético.
![alt text](https://camo.githubusercontent.com/ad1da211b35b60b23fb095a64e76dc6504d0c3229e853bd82a69a4d5d27bbb88/68747470733a2f2f692e696d6775722e636f6d2f594947477453472e706e67)

Autora: Jessica Del Pallo 
