#include <iostream>
#include <laboratory 1/TelemetryProcessor.h>
#include <laboratory 1/CloudTelemetrySender.h>
#include <laboratory 1/LocalFileTelemetrySender.h>
#include <laboratory 2/BusinessLogic.h>
#include <laboratory 2/SmartThermometer.h>
#include <laboratory 2/WiredCamera.h>
#include <laboratory 3/IEngine.h>
#include <memory>
#include <filesystem>

int main()
{
    std::cout << "--- Start laboratory #1 ---\n";

    std::cout << "[CLOUD] Creating cloud sender\n";
    auto cloud_sender{ std::make_shared<CloudTelemetrySender>("https://api.iot-gateway.metrics")};

    std::cout << "[CLOUD] Initialization telemetry with cloud sender\n";
    TelemetryProcessor telemetry_cloud{ cloud_sender };

    std::cout << "[CLOUD] Start metric processing\n";
    telemetry_cloud.process_metrics();

    std::cout << "[LOCAL] Creating local file\n";
    const std::string PATH_FILE_TARGET{ (std::filesystem::absolute(__FILE__).parent_path() / "headers" / "laboratory 1" / "test_file.txt").string()};
    auto local_file{ std::make_shared<LocalFileTelemetrySender>(PATH_FILE_TARGET) };

    std::cout << "[LOCAL] Initialization telemetry with local file\n";
    TelemetryProcessor telemetry_local_file{ local_file };

    std::cout << "[LOCAL] Start metric processing\n";
    telemetry_local_file.process_metrics();

    std::cout << "--- End laboratory #1 ---\n\n";

    
    std::cout << "--- Start laboratory #2 ---\n";
    SmartThermometer thermometer{ 95.0, PowerMode::Performance, 22.5, "home_wi_fi"};
    optimize_battery(thermometer);
    sync_sensor_data(thermometer, thermometer);

    WiredCamera camera{ "home_wired_camera" };
    sync_sensor_data(camera, camera);
    //optimize_battery(camera); // ОШИБКА КОМПИЛЯЦИИ: camera не обладает IPowerManaged.
    std::cout << "--- End laboratory #2 ---\n\n";


    std::cout << "--- Start laboratory #3 ---\n";

    std::cout << "Create 'engine' is value 'core'.\n";
    auto engine{ create_engine("core") };

    if (engine)
    {
        engine->initialize();
        engine->execute_task("render scene");
    }

    std::cout << "--- End laboratory #3 ---\n\n";

    return 0;
}