#ifndef CANOPENNODE_ESP32_H
#define CANOPENNODE_ESP32_H

#if CONFIG_USE_CANOPENNODE

#include "CANopen.h"

#ifdef __cplusplus
extern "C"
{
#endif

bool CO_ESP32_init();

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_USE_CANOPENNODE */
#endif /* CANOPENNODE_ESP32_H */
