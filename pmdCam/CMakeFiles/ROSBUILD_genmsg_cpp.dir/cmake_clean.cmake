FILE(REMOVE_RECURSE
  "src/pmdCam/msg"
  "msg_gen"
  "msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "msg_gen/cpp/include/pmdCam/data_flow.h"
  "msg_gen/cpp/include/pmdCam/image_box.h"
  "msg_gen/cpp/include/pmdCam/pmd_settings.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
