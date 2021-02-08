#include <PubSubClient.h>

#include <UIPEthernet.h>

#include <utility/logging.h>

#include <SPI.h>

//Variável utilizada para enviar as mensagens utilizando o cliente MQTT
bool mensagem; 

//Define o endereço MAC que será utilizado
byte mac[] = {0xEE, 0x27, 0xAE, 0xFD, 0x0D, 0x83};

int pino2 = 2;

bool estado_sensor;

//Inicia o cliente Ethernet
EthernetClient client;

//Inicia o client MQTT
PubSubClient mqttClient(client);

void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
    Serial.begin(9600);
    pinMode(pino2, INPUT_PULLUP);

    //Define o IP e Porta TCP do Broker MQTT que vamos utilizar
    mqttClient.setServer("54.161.191.80", 1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

    //Exibe uma linha em branco 
    Serial.println("");

}

void loop() {

    //Define o nome do cliente MQTT e efetua a conexão com o servidor.
    mqttClient.connect("jessicaalsin");

    Serial.println(mensagem);

    //Função que verifica a conexão entre o Cliente e o Broker e evita a queda de conexão entre eles.
    mqttClient.loop();

    estado_sensor = digitalRead(pino2);
    Serial.println(estado_sensor);

  if (estado_sensor == 1){

    /*
      Variável que envia a mensagem e armazena o valor de '1' caso 
      a mensagem seja enviada com sucesso e '0' caso o envio falhe
    */
    mensagem = mqttClient.publish("jessicaalsin", "ABERTO!");
    
    Serial.println("O rack está ABERTO");
  }
  else {
    /*
      Variável que envia a mensagem e armazena o valor de '1' caso 
      a mensagem seja enviada com sucesso e '0' caso o envio falhe
    */
    mensagem = mqttClient.publish("jessicaalsin", "FECHADO!");
    
    Serial.println("O rack está FECHADO");
  }
}