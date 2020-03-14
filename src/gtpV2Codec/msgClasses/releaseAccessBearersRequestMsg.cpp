/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/******************************************************************************
 *
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/GtpV2StackCodeGen/tts/msgtemplate.cpp.tt>
 ******************************************************************************/ 

#include "releaseAccessBearersRequestMsg.h"
#include "../ieClasses/manual/gtpV2Ie.h"
#include "../ieClasses/gtpV2IeFactory.h"
#include "../ieClasses/ebiIe.h"
#include "../ieClasses/nodeTypeIe.h"
#include "../ieClasses/indicationIe.h"
#include "../ieClasses/secondaryRatUsageDataReportIe.h"

ReleaseAccessBearersRequestMsg::ReleaseAccessBearersRequestMsg()
{
    msgType = ReleaseAccessBearersRequestMsgType;

}

ReleaseAccessBearersRequestMsg::~ReleaseAccessBearersRequestMsg()
{

}

bool ReleaseAccessBearersRequestMsg::encodeReleaseAccessBearersRequestMsg(MsgBuffer &buffer,
                        ReleaseAccessBearersRequestMsgData
							const &data)
{
    bool rc = false;
    GtpV2IeHeader header;
    Uint16 startIndex = 0;
    Uint16 endIndex = 0;
    Uint16 length = 0;

    if (data.listOfRabsIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = EbiIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        EbiIe listOfRabs=
        dynamic_cast<
        EbiIe&>(GtpV2IeFactory::getInstance().getIeObject(EbiIeType));
        rc = listOfRabs.encodeEbiIe(buffer, data.listOfRabs);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: listOfRabs\n");
            return false;
        }
    }

    if (data.originatingNodeIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = NodeTypeIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        NodeTypeIe originatingNode=
        dynamic_cast<
        NodeTypeIe&>(GtpV2IeFactory::getInstance().getIeObject(NodeTypeIeType));
        rc = originatingNode.encodeNodeTypeIe(buffer, data.originatingNode);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: originatingNode\n");
            return false;
        }
    }

    if (data.indicationFlagsIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = IndicationIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        IndicationIe indicationFlags=
        dynamic_cast<
        IndicationIe&>(GtpV2IeFactory::getInstance().getIeObject(IndicationIeType));
        rc = indicationFlags.encodeIndicationIe(buffer, data.indicationFlags);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: indicationFlags\n");
            return false;
        }
    }

    if (data.secondaryRatUsageDataReportIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = SecondaryRatUsageDataReportIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        SecondaryRatUsageDataReportIe secondaryRatUsageDataReport=
        dynamic_cast<
        SecondaryRatUsageDataReportIe&>(GtpV2IeFactory::getInstance().getIeObject(SecondaryRatUsageDataReportIeType));
        rc = secondaryRatUsageDataReport.encodeSecondaryRatUsageDataReportIe(buffer, data.secondaryRatUsageDataReport);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: secondaryRatUsageDataReport\n");
            return false;
        }
    }
    return rc;

}

bool ReleaseAccessBearersRequestMsg::decodeReleaseAccessBearersRequestMsg(MsgBuffer &buffer,
 ReleaseAccessBearersRequestMsgData 
 &data, Uint16 length)
{

    bool rc = false;
    GtpV2IeHeader ieHeader;
  
    set<Uint16> mandatoryIeLocalList = mandatoryIeSet;
    while (buffer.lengthLeft() > IE_HEADER_SIZE)
    {
        GtpV2Ie::decodeGtpV2IeHeader(buffer, ieHeader);
        if (ieHeader.length > buffer.lengthLeft())
        {
            // We do not have enough bytes left in the message for this IE
            errorStream.add((char *)"IE Length exceeds beyond message boundary\n");
            errorStream.add((char *)"  Offending IE Type: ");
            errorStream.add(ieHeader.ieType);
            errorStream.add((char *)"\n  Ie Length in Header: ");
            errorStream.add(ieHeader.length);
            errorStream.add((char *)"\n  Bytes left in message: ");
            errorStream.add(buffer.lengthLeft());
            errorStream.endOfLine();
            return false;
        }

        switch (ieHeader.ieType){
     
            case EbiIeType:
            {
                EbiIe ieObject =
                dynamic_cast<
                EbiIe&>(GtpV2IeFactory::getInstance().getIeObject(EbiIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeEbiIe(buffer, data.listOfRabs, ieHeader.length);

                    data.listOfRabsIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: listOfRabs\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case NodeTypeIeType:
            {
                NodeTypeIe ieObject =
                dynamic_cast<
                NodeTypeIe&>(GtpV2IeFactory::getInstance().getIeObject(NodeTypeIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeNodeTypeIe(buffer, data.originatingNode, ieHeader.length);

                    data.originatingNodeIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: originatingNode\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case IndicationIeType:
            {
                IndicationIe ieObject =
                dynamic_cast<
                IndicationIe&>(GtpV2IeFactory::getInstance().getIeObject(IndicationIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeIndicationIe(buffer, data.indicationFlags, ieHeader.length);

                    data.indicationFlagsIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: indicationFlags\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case SecondaryRatUsageDataReportIeType:
            {
                SecondaryRatUsageDataReportIe ieObject =
                dynamic_cast<
                SecondaryRatUsageDataReportIe&>(GtpV2IeFactory::getInstance().getIeObject(SecondaryRatUsageDataReportIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeSecondaryRatUsageDataReportIe(buffer, data.secondaryRatUsageDataReport, ieHeader.length);

                    data.secondaryRatUsageDataReportIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: secondaryRatUsageDataReport\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }

            default:
            {
                // Unknown IE print error
                errorStream.add((char *)"Unknown IE Type: ");
                errorStream.add(ieHeader.ieType);
                errorStream.endOfLine();
                buffer.skipBytes(ieHeader.length);
            }
        }
    }
    return rc; // TODO validations
}

void ReleaseAccessBearersRequestMsg::
displayReleaseAccessBearersRequestMsgData_v(ReleaseAccessBearersRequestMsgData const &data, Debug &stream)
{
    stream.incrIndent();
    stream.add((char *)"ReleaseAccessBearersRequestMsg:");
    stream.endOfLine();
    stream.incrIndent();
        
    
    if (data.listOfRabsIePresent)
    {


        stream.add((char *)"IE - listOfRabs:");
        stream.endOfLine();
        EbiIe listOfRabs=
        dynamic_cast<
        EbiIe&>(GtpV2IeFactory::getInstance().getIeObject(EbiIeType));
        listOfRabs.displayEbiIe_v(data.listOfRabs, stream);

    }
    if (data.originatingNodeIePresent)
    {


        stream.add((char *)"IE - originatingNode:");
        stream.endOfLine();
        NodeTypeIe originatingNode=
        dynamic_cast<
        NodeTypeIe&>(GtpV2IeFactory::getInstance().getIeObject(NodeTypeIeType));
        originatingNode.displayNodeTypeIe_v(data.originatingNode, stream);

    }
    if (data.indicationFlagsIePresent)
    {


        stream.add((char *)"IE - indicationFlags:");
        stream.endOfLine();
        IndicationIe indicationFlags=
        dynamic_cast<
        IndicationIe&>(GtpV2IeFactory::getInstance().getIeObject(IndicationIeType));
        indicationFlags.displayIndicationIe_v(data.indicationFlags, stream);

    }
    if (data.secondaryRatUsageDataReportIePresent)
    {


        stream.add((char *)"IE - secondaryRatUsageDataReport:");
        stream.endOfLine();
        SecondaryRatUsageDataReportIe secondaryRatUsageDataReport=
        dynamic_cast<
        SecondaryRatUsageDataReportIe&>(GtpV2IeFactory::getInstance().getIeObject(SecondaryRatUsageDataReportIeType));
        secondaryRatUsageDataReport.displaySecondaryRatUsageDataReportIe_v(data.secondaryRatUsageDataReport, stream);

    }

    stream.decrIndent();
    stream.decrIndent();
}
