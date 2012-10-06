FILE(REMOVE_RECURSE
  "src/pmdCam/msg"
  "msg_gen"
  "msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "msg_gen/lisp/data_flow.lisp"
  "msg_gen/lisp/_package.lisp"
  "msg_gen/lisp/_package_data_flow.lisp"
  "msg_gen/lisp/image_box.lisp"
  "msg_gen/lisp/_package.lisp"
  "msg_gen/lisp/_package_image_box.lisp"
  "msg_gen/lisp/pmd_settings.lisp"
  "msg_gen/lisp/_package.lisp"
  "msg_gen/lisp/_package_pmd_settings.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
