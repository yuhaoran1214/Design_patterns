cmake_minimum_required(VERSION 2.8)

project(design_pattern)

# 创建型
add_subdirectory(${PROJECT_SOURCE_DIR}/factory_method_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/simple_factory_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/abstract_factory_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/singleton_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/builder_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/prototype_pattern)

# 结构型
add_subdirectory(${PROJECT_SOURCE_DIR}/adapter_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/bridge_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/composite_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/decorator_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/facade_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/flyweight_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/proxy_pattern)

# 行为型
add_subdirectory(${PROJECT_SOURCE_DIR}/command_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/chain_of_responsibility_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/interpreter_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/iterator_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/mediator_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/memento_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/observer_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/state_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/strategy_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/template_method_pattern)
add_subdirectory(${PROJECT_SOURCE_DIR}/visitor_pattern)
