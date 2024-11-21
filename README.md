i) Descrição do Funcionamento e Uso
O protótipo monitora a temperatura de equipamentos industriais utilizando o sensor LM35, que converte a temperatura em uma tensão proporcional. O Arduino Uno processa os dados e exibe as leituras no display LCD 16x2. O módulo ESP8266 envia os dados via Wi-Fi para o broker MQTT test.mosquitto.org, permitindo o monitoramento remoto.
Para reproduzir o projeto:
- Conecte o LM35, o display LCD e o ESP8266 ao Arduino Uno.
- Configure a rede Wi-Fi no ESP8266 e o broker MQTT.
- Execute o código para capturar e exibir a temperatura e enviar os dados para o MQTT.

ii) Software Desenvolvido e Documentação de Código
O código realiza:
- Leitura de Temperatura: Converte o sinal do LM35 para temperatura em Celsius.
- Exibição no Display: Mostra a temperatura no LCD 16x2.
- Envio via MQTT: O ESP8266 transmite os dados de temperatura para o broker MQTT via Wi-Fi.

iii) Descrição do Hardware Utilizado
- Plataforma: Arduino Uno processa os dados e controla o display.
- Sensor: LM35, que mede a temperatura e gera uma saída proporcional.
- Display: LCD 16x2 exibe a temperatura em tempo real.
- Comunicação: ESP8266, para conectividade Wi-Fi e envio de dados via MQTT.
- Alimentação: Fornecida pelo cabo USB do Arduino Uno.

iv) Documentação das Interfaces, Protocolos e Módulos de Comunicação
- Interfaces: Comunicação serial entre Arduino e display; serial para monitoramento.
- Protocolos: Wi-Fi para conectar o ESP8266 à rede e MQTT para enviar dados ao broker.
- Módulos: ESP8266 para comunicação sem fio e test.mosquitto.org como broker MQTT.
v) Comunicação/Controle via Internet (TCP/IP) e Uso do Protocolo MQTT
O sistema utiliza Wi-Fi (TCP/IP) para conectar o ESP8266 ao broker MQTT. O protocolo MQTT é usado para enviar os dados de temperatura em tempo real, permitindo monitoramento remoto e escalabilidade para integrações futuras.
