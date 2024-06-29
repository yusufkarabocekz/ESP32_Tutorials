#include "driver/uart.h"
#include "esp_log.h"

#define UART_TXD_PIN (GPIO_NUM_17) // TX pin (STM32'ye bağlı RX pini)
#define UART_RXD_PIN (GPIO_NUM_16) // RX pin (STM32'ye bağlı TX pini)

void setup() {
  Serial.begin(115200);

  const uart_port_t uart_num = UART_NUM_2; // UART2 kullan
  uart_config_t uart_config = {
    .baud_rate = 115200,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .rx_flow_ctrl_thresh = 122,
    .source_clk = UART_SCLK_APB,
  };

  // UART parametrelerini yapılandır
  ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
  ESP_ERROR_CHECK(uart_set_pin(uart_num, UART_TXD_PIN, UART_RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));

  const int uart_buffer_size = (1024 * 2);
  // UART sürücüsünü yükle
  ESP_ERROR_CHECK(uart_driver_install(uart_num, uart_buffer_size, uart_buffer_size, 0, NULL, 0));
}

void loop() {
  // UART üzerinden veri oku
  const uart_port_t uart_num = UART_NUM_2; // UART2 kullan
  uint8_t data[128];
  int length = 0;

  // Tamponlanan veri uzunluğunu al
  ESP_ERROR_CHECK(uart_get_buffered_data_len(uart_num, (size_t*)&length));
  
  // UART üzerinden veri oku
  length = uart_read_bytes(uart_num, data, sizeof(data) - 1, 100 / portTICK_RATE_MS);

  if (length > 0) {
    data[length] = '\0'; // String'i null-terminate yap
    Serial.print("Received: ");
    Serial.println((char*)data);
  }

  delay(100); // Seri Monitör'ü aşırı doldurmamak için küçük bir gecikme ekleyin
}
