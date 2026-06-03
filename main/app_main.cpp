#include "tasks/HealthMonitorTask.hpp"
#include "tasks/LoggerTask.hpp"
#include "tasks/SensorTask.hpp"

#include "esp_log.h"

namespace {
constexpr const char* kTag = "app_main";
}

extern "C" void app_main(void)
{
    ESP_LOGI(kTag, "Starting ESP32 FreeRTOS Sensor Hub");

    sensor_hub::tasks::start_sensor_task();
    sensor_hub::tasks::start_logger_task();
    sensor_hub::tasks::start_health_monitor_task();

    ESP_LOGI(kTag, "Phase 1 tasks started");
}
