cmake_minimum_required(VERSION 3.16)

project(DungeonCrawlerv2 LANGUAGES CXX)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
	

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DungeonCrawlerv2 main.cpp
    tile.h tile.cpp
    Floor.h
    Wall.h
    Portal.h
    character.h character.cpp
    level.h level.cpp
    AbstractView.h
    Input.h
    terminalui.h terminalui.cpp
    dungeoncrawler.h dungeoncrawler.cpp
    Passive.h
    Active.h


    Pit.h
    Ramp.h
    AbstractController.h
    startscreen.h startscreen.cpp startscreen.ui
    mainwindow.h mainwindow.cpp mainwindow.ui
    graphicalui.h graphicalui.cpp
    resources.qrc
)
target_link_libraries(DungeonCrawlerv2
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS DungeonCrawlerv2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
