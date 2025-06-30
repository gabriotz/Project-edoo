include("C:/Users/gmome/Desktop/Project-edoo/build/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/GUI_BIBLIOTECA-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/gmome/Desktop/Project-edoo/build/GUI_BIBLIOTECA.exe
    GENERATE_QT_CONF
)
