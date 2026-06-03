#include "tasks/LoggerTask.hpp"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

namespace sensor_hub::tasks {
namespace {

constexpr const char* kTag = "logger_task";
constexpr uint32_t kStackSize = 3072;
constexpr UBaseType_t kPriority = 3;
constexpr TickType_t kPeriod = pdMS_TO_TICKS(2000);

void logger_task(void*)
{
    uint32_t heartbeat_count = 0;

    while (true) {
        ESP_LOGI(kTag, "Heartbeat %lu", static_cast<unsigned long>(heartbeat_count++));
        vTaskDelay(kPeriod);
    }
}

}  // namespace

void start_logger_task()
{
    xTaskCreate(
        logger_task,
        "logger",
        kStackSize,
        nullptr,
        kPriority,
        nullptr
    );
}

}  // namespace sensor_hub::tasks
