#include "Lab1/Widget.hpp"
#include "Lab1/ButtonWidget.hpp"
#include "Lab1/TextWidget.hpp"
#include "Lab1/UIEngine.hpp"
#include "Lab2/DataExporter.hpp"
#include "Lab2/RawExporter.hpp"
#include "Lab2/JsonExporter.hpp"
#include "Lab2/XmlExporter.hpp"
#include "Lab2/ExportManager.hpp"
#include "Lab3/NetworkProcessor.hpp"
#include "Lab3/HttpProcessor.hpp"
#include "Lab3/FtpProcessor.hpp"
#include "Lab3/NetworkManager.hpp"
#include <iostream>
#include <memory>
#include <vector>

int main()
{
    std::cout << "*** Start laboratory #1 - Guaranteeing GUI invariants using NVI ***\n";

    std::vector<std::shared_ptr<Widget>> ui_element{};
    ui_element.push_back(std::make_shared<ButtonWidget>());
    ui_element.push_back(std::make_shared<TextWidget>());

    UIEngine::render_UI(ui_element);

    std::cout << "*** End laboratory #1 ***\n\n";


    std::cout << "*** Start laboratory #2 - Extending default behavior via NVI ***\n";

    std::vector<std::shared_ptr<DataExporter>> exporters{};
    exporters.push_back(std::make_shared<RawExporter>());
    exporters.push_back(std::make_shared<JsonExporter>());
    exporters.push_back(std::make_shared<XmlExporter>());

    ExportManager::process_exports(exporters);

    std::cout << "*** End laboratory #2 ***\n\n";


    std::cout << "*** Start laboratory #3 - Freezing NVI using the final specifier. ***\n\n";

    std::vector<std::shared_ptr<NetworkProcessor>> processors{};
    processors.push_back(std::make_shared<HttpProcessor>());
    processors.push_back(std::make_shared<FtpProcessor>());

    NetworkManager::run_network_pipeline(processors);

    std::cout << "*** End laboratory #3 ***\n";
}