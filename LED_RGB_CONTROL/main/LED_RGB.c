#include "LED_RGB.h"
#include "esp_err.h"


/**
 * @brief Configures the LEDC timer and channels for RGB LED control.
 * 
 * This function initializes the LEDC (LED Controller) hardware of the ESP32 
 * to control the Red, Green, and Blue channels of an RGB LED. Each channel 
 * is configured with a specific GPIO pin and associated with a timer.
 */


void configure_led_rgb(void) {
    // Configure the LEDC timer
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_DUTY_RES,// LEDC timer resolution
        .freq_hz = LEDC_FREQUENCY, // LEDC timer frequency 
        .speed_mode = LEDC_MODE, // LEDC speed mode
        .timer_num = LEDC_TIMER // LEDC timer
    };
    // Check if the configuration was successful
    esp_err_t check= (ledc_timer_config(&ledc_timer));
    if (check != ESP_OK) {
        printf("Error en la configuración del temporizador\n");
        return;
    }
  
    // Configure the LED RGB channels

    // Red channel
    ledc_channel_config_t ledc_channel_r = {
        .channel = LEDC_CHANNEL_R, // LEDC channel
        .duty = 0, // Initial duty cycle
        .gpio_num = LEDC_OUTPUT_IO_R, // GPIO pin (18)
        .speed_mode = LEDC_MODE, // LEDC speed mode
        .timer_sel = LEDC_TIMER // LEDC timer
    };
    // Check if the configuration was successful
    check= (ledc_channel_config(&ledc_channel_r));
    if (check != ESP_OK) {
        printf("Error en canal led rojo \n");
        return;
    }

    // Green channel
    ledc_channel_config_t ledc_channel_g = {
        .channel = LEDC_CHANNEL_G, // LEDC channel
        .duty = 0, // Initial duty cycle
        .gpio_num = LEDC_OUTPUT_IO_G, // GPIO pin (19)
        .speed_mode = LEDC_MODE, // LEDC speed mode
        .timer_sel = LEDC_TIMER // LEDC timer
    };
    // Check if the configuration was successful
    check=(ledc_channel_config(&ledc_channel_g));
    if (check != ESP_OK) {
        printf("Error en canal led verde \n");
        return;
    }

    // Blue channel
    ledc_channel_config_t ledc_channel_b = {
        .channel = LEDC_CHANNEL_B, // LEDC channel
        .duty = 0, // Initial duty cycle
        .gpio_num = LEDC_OUTPUT_IO_B, // GPIO pin (21)
        .speed_mode = LEDC_MODE, // LEDC speed mode
        .timer_sel = LEDC_TIMER // LEDC timer
    };
    // Check if the configuration was successful
    check=(ledc_channel_config(&ledc_channel_b));
    if (check != ESP_OK) {
        printf("Error en canal led azul \n");
        return;
    }
}

// Set the color of the RGB LED
void set_rgb_color(uint8_t red, uint8_t green, uint8_t blue) {
    // Set the duty cycle for each channel

    // Convert the percentage values to 8-bit values (0-255)
    red = (red * 255) / 100;
    green = (green * 255) / 100;
    blue = (blue * 255) / 100;
    // Red channel
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_R, red);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_R);

    // Green channel
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_G, green);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_G);

    // Blue channel
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_B, blue);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_B);
}
