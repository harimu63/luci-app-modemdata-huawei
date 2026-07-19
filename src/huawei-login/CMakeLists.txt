cmake_minimum_required(VERSION 3.10)

project(modemdata-huawei C)

set(CMAKE_C_STANDARD 99)

add_executable(modemdata-huawei
    main.c
    http.c
    xml.c
    scram.c
    api.c
    session.c
    utils.c
)

target_link_libraries(modemdata-huawei
    ssl
    crypto
)
