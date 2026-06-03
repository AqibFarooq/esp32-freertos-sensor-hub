#include "tasks/SensorTask.hpp"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

namespace sensor_hub::tasks {
namespace {

constexpr const char* kTag = "sensor_task";
constexpr uint32_t kStackSize = 3072;
constexpr UBaseType_t kPriority = 5;
constexpr TickType_t kPeriod = pdMS_TO_TICKS(1000);

void sensor_task(void*)
{
    uint32_t sample_count = 0;

    while (true) {
        const int simulated_temperature_c = 24 + static_cast<int>(sample_count % 5);
        ESP_LOGI(
            kTag,
            "Sample %lu: temperature=%d C",
            static_cast<unsigned long>(sample_count++),
            simulated_temperature_c
        );
        vTaskDelay(kPeriod);
    }
}

}  // namespace

void start_sensor_task()
{
    xTaskCreate(
        sensor_task,
        "sensor",
        kStackSize,
        nullptr,
        kPriority,
        nullptr
    );
}

}  // namespace sensor_hub::tasks
