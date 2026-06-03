#include "tasks/HealthMonitorTask.hpp"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

namespace sensor_hub::tasks {
namespace {

constexpr const char* kTag = "health_task";
constexpr uint32_t kStackSize = 3072;
constexpr UBaseType_t kPriority = 4;
constexpr TickType_t kPeriod = pdMS_TO_TICKS(5000);

void health_monitor_task(void*)
{
    while (true) {
        ESP_LOGI(kTag, "Free heap: %lu bytes", static_cast<unsigned long>(esp_get_free_heap_size()));
        vTaskDelay(kPeriod);
    }
}

}  // namespace

void start_health_monitor_task()
{
    xTaskCreate(
        health_monitor_task,
        "health_monitor",
        kStackSize,
        nullptr,
        kPriority,
        nullptr
    );
}

}  // namespace sensor_hub::tasks
