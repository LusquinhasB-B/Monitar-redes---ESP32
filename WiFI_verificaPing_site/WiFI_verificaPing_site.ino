//CÓDIGO PARA CONECTAR A UM ROTEADOR E FAZER UM PING COM ESP32 PARA VERIFICAR SE O ESP32 ESTÁ NA WEB VALIDANDO DOIS SITES

#include <WiFi.h>
#include  <ESP32Ping.h>

const char* ssid = "IoT-Senac";
const char* password = "Senac@2025"

//"Bancoo de dados" com os sites pings
const char* site[] = {"www.senactaboao.com.br", "www.google.com.br", "www.marcoscosta.eti.br"};

void setup() {
  //Inicia a comunicação serial entre os dispositivos
  Serial.begin(115200);
  //Chamada da função para a conexão WiFi
  conectaWiFi();
  Serial.println("*************************************************")
    //Chamada da função para verificação dos pings
  verificaSite();
}
//***********************************************************
void loop() {
//Não possui nenhuma execução em looping

}

void conectaWifi(){
  Serial.println("Conectado em ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado!");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP);

}//Void conectaWiFi()
  
void verificaSite(){
  if (WiFi.status () != WL_CONNECTED){
  Serial.println("WiFI não está conectado. Não será possivel rfealizar o ping.");
  return;
  }

  for (int = x; x < sizeof(site) /  sizeof(site[0]); x++){
    Serial.print("Pinngando o site: ");
    Serial.print(String(site[x]));

    //Variável booleana(Verdadeira ou Falsa) que recebe True ou False do ping realizado de até 5 segundos
    bool success = Ping.ping(site[x], 5);
    

    if (!success) {
      Serial.println("O ping falhou!");
    } else {
      Serial.println("Ping no site foi realizado com sucesso!");
    }//else
  }//for

  Serial.println("***********************************************************")
}//void verificaSite()
