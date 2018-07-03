#ifndef _ROS_hector_worldmodel_msgs_Object_h
#define _ROS_hector_worldmodel_msgs_Object_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "hector_worldmodel_msgs/ObjectInfo.h"
#include "hector_worldmodel_msgs/ObjectState.h"

namespace hector_worldmodel_msgs
{

  class Object : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::PoseWithCovariance _pose_type;
      _pose_type pose;
      typedef hector_worldmodel_msgs::ObjectInfo _info_type;
      _info_type info;
      typedef hector_worldmodel_msgs::ObjectState _state_type;
      _state_type state;

    Object():
      header(),
      pose(),
      info(),
      state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
      offset += this->state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->info.deserialize(inbuffer + offset);
      offset += this->state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "hector_worldmodel_msgs/Object"; };
    const char * getMD5(){ return "02dea96e80640703553490052f13918d"; };

  };

}
#endif