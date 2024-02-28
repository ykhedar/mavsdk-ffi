# Build MAVSDK Library
git clone https://github.com/mavlink/MAVSDK.git
cmake -Bthird_party/mavlink/build -Sthird_party/mavlink
cmake --build third_party/mavlink/build
cmake -Bbuild/default -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=false -H.
cmake --build build/default -j8
