cmake_minimum_required(VERSION 3.19)
project(GUI_BIBLIOTECA LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

# VERSÃO CORRETA do bloco em CMakeLists.txt

# VERSÃO CORRETA do bloco em CMakeLists.txt

qt_add_executable(GUI_BIBLIOTECA
    WIN32 MACOSX_BUNDLE

    # Frontend
    main.cpp
    mainwindow.cpp
    mainwindow.ui
    mainwindow.h  
    loginwindow.cpp
    loginwindow.ui
    loginwindow.h   
    registrationwindow.cpp
    registrationwindow.ui
    registrationwindow.h 
    addbookwindow.h addbookwindow.cpp addbookwindow.ui
    

    # Backend
    # Backend
    ../backend/src/cadastros.cpp
    ../backend/src/usuario.cpp
    ../backend/src/aluno.cpp
    ../backend/src/professor.cpp
    ../backend/src/acervo.cpp
    ../backend/src/livros.cpp
    
    loanbookwindow.h loanbookwindow.cpp loanbookwindow.ui
    seeallbookswindow.h seeallbookswindow.cpp seeallbookswindow.ui
    userbookswindow.h userbookswindow.cpp userbookswindow.ui


    
    
        
)
target_include_directories(GUI_BIBLIOTECA PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../backend/headers")
target_link_libraries(GUI_BIBLIOTECA
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS GUI_BIBLIOTECA
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET GUI_BIBLIOTECA
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
