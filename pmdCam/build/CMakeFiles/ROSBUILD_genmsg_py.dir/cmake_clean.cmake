FILE(REMOVE_RECURSE
  "../src/pmdCam/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/pmdCam/msg/__init__.py"
  "../src/pmdCam/msg/_pmd_settings.py"
  "../src/pmdCam/msg/_data_flow.py"
  "../src/pmdCam/msg/_image_box.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
