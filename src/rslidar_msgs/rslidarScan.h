#ifndef _ROS_rslidar_msgs_rslidarScan_h
#define _ROS_rslidar_msgs_rslidarScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "rslidar_msgs/rslidarPacket.h"

namespace rslidar_msgs
{

  class rslidarScan : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t packets_length;
      typedef rslidar_msgs::rslidarPacket _packets_type;
      _packets_type st_packets;
      _packets_type * packets;

    rslidarScan():
      header(),
      packets_length(0), packets(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->packets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->packets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->packets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->packets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->packets_length);
      for( uint32_t i = 0; i < packets_length; i++){
      offset += this->packets[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t packets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      packets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      packets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      packets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->packets_length);
      if(packets_lengthT > packets_length)
        this->packets = (rslidar_msgs::rslidarPacket*)realloc(this->packets, packets_lengthT * sizeof(rslidar_msgs::rslidarPacket));
      packets_length = packets_lengthT;
      for( uint32_t i = 0; i < packets_length; i++){
      offset += this->st_packets.deserialize(inbuffer + offset);
        memcpy( &(this->packets[i]), &(this->st_packets), sizeof(rslidar_msgs::rslidarPacket));
      }
     return offset;
    }

    const char * getType(){ return "rslidar_msgs/rslidarScan"; };
    const char * getMD5(){ return "ff6baa58985b528481871cbaf1bb342f"; };

  };

}
#endif