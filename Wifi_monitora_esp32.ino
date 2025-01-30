#include "WiFi.h"

void setup() {

  Serial.begin(115200);//Iniciando a comunicação serial / Velocidade -> Comunicação Serial
  Serial.println("Inciando comunicação Wifi..."); 
  WiFi.mode(WIFI_STA); //Modo de conexão, neste caso iremos procurar rotedores
  Serial.println("Configuração concluída!");
}

void loop() {
  Serial.println("Procurando rede...");

  int quantidadeRedes = WiFi.scanNetworks(); //Quantidade de redes encontradas
  Serial.println("Verificação concluída. ");

  if (quantidadeRedes == 0){
    Serial.println("Nenhuma rede encontrada!");
  }
  
  else{
    Serial.print("Total de rede(s) encontradas: ");
    Serial.println(quantidadeRedes);

    for (int i = 0; i < quantidadeRedes; i++){
      Serial.print(i + 1); //Sequência numérica
      Serial.print(": ");
      
      //Intensidade do Sinal da rede
      Serial.print(WiFi.SSID(i));
      Serial.print(" - Sinal (");

      Serial.print(WiFi.RSSI(i));
      Serial.print(" - Possui senha? ");
      
      //WIFI_AUTH_OPEN verifica se a rede possui senha
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "NÃO" : "SIM");
      delay(50);
  }
  delay(5000); //Tempo para a próxima verificação
 }
}
