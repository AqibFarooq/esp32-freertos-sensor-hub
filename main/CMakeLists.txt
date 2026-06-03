idf_component_register(
    SRCS
        "app_main.cpp"
        "../src/tasks/HealthMonitorTask.cpp"
        "../src/tasks/LoggerTask.cpp"
        "../src/tasks/SensorTask.cpp"
    INCLUDE_DIRS
        "../include"
)

set_property(TARGET ${COMPONENT_LIB} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${COMPONENT_LIB} PROPERTY CXX_STANDARD_REQUIRED ON)
