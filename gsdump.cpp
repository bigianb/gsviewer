#include "gsdump.h"

#include <cstdint>

GSDump::GSDump()
{

}

static uint32_t readU32(std::vector<char>buf, int idx)
{
    return reinterpret_cast<uint32_t *>(buf.data() + idx)[0];
}

/*
 *  GS Dump format:
 *
 *  u32     0xFFFFFFFF
 *  u32     headerSize
 *
 *  Header
 *  ------
 *
 *  u32 stateVersion
 *	u32 stateSize
 *	u32 serialOffset
 *	u32 serialSize
 *	u32 crc
 *	u32 screenshotWidth
 *	u32 screenshotHeight
 *	u32 screenshotOffset
 *	u32 screenshotSize
 *
 *  possible serial string
 *  possible screenshot
 *
 *  u32 state size
 *  [state data/size]
 *  [PMODE/0x2000]
 */

void GSDump::setData(std::vector<char>buf)
{
    int index = 0;

    uint32_t id = readU32(buf, index);
    index += 4;
    if (id != 0xFFFFFFFF){
        // TODO: Throw an exception
        return;
    }


    uint32_t headerSize = readU32(buf, index);
    index += 4;

    uint32_t stateVersion = readU32(buf, index); index += 4;
    uint32_t stateSize = readU32(buf, index); index += 4;
    uint32_t serialOffset = readU32(buf, index); index += 4;
    uint32_t serialSize = readU32(buf, index); index += 4;
    uint32_t crc = readU32(buf, index); index += 4;
    uint32_t screenshotWidth = readU32(buf, index); index += 4;
    uint32_t screenshotHeight = readU32(buf, index); index += 4;
    uint32_t screenshotOffset = readU32(buf, index); index += 4;
    uint32_t screenshotSize = readU32(buf, index); index += 4;

    //std::vector<char> state = std::vector<char>(buf.begin() + index, buf.begin() + index + stateDataLen);
    //index += stateDataLen;

}
