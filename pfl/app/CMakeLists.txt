add_executable(app src/main.cpp)
target_compile_features(app PUBLIC cxx_std_20)
target_include_directories(app PUBLIC inc)
