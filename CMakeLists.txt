set(srcs "")
set(include_dirs "")
set(private_include_dirs "")
set(private_requirements "")
set(ldfragments "")
set(co_dir "CANopenNode")
set(co_port_dir "port")

if(CONFIG_USE_CANOPENNODE)

   # Add wrapper
    list(APPEND srcs "CANopenNode_ESP32.c")
    
    # Glob the common CANopen sources
    file(GLOB canopen_301_srcs "${co_dir}/301/*.c")
    file(GLOB canopen_303_srcs "${co_dir}/303/*.c")
    file(GLOB canopen_304_srcs "${co_dir}/304/*.c")
    file(GLOB canopen_305_srcs "${co_dir}/305/*.c")
    file(GLOB canopen_309_srcs "${co_dir}/309/*.c")    
    file(GLOB canopen_port_srcs "${co_port_dir}/*.c")
    
    list(APPEND srcs 
        "${co_dir}/CANopen.c"
        ${canopen_301_srcs}
        ${canopen_303_srcs}
        ${canopen_304_srcs}
        ${canopen_305_srcs}
        ${canopen_309_srcs}        
        ${canopen_port_srcs})
    
  list(APPEND include_dirs
    "."
    "${co_dir}"
    "${co_port_dir}")

endif() #CONFIG_USE_CANOPENNODE

if(CONFIG_CO_LED_ENABLE)
  list(APPEND srcs
    "${co_dir}/303/CO_LEDs.c")
endif() #CONFIG_CO_LED_ENABLE

idf_component_register(SRCS ${srcs}
                    INCLUDE_DIRS ${include_dirs}
                    PRIV_INCLUDE_DIRS ${private_include_dirs}
                    LDFRAGMENTS ${ldfragments}
                    PRIV_REQUIRES ${private_requirements}
                    REQUIRES freertos driver main)
