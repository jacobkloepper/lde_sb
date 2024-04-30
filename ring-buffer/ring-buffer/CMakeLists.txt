add_executable(ring-buffer src/main.cpp src/ringbuf.cpp)
target_compile_features(ring-buffer PUBLIC cxx_std_20)
target_include_directories(ring-buffer PUBLIC inc)
