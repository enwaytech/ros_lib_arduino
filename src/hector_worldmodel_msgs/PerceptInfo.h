#ifndef _ROS_hector_worldmodel_msgs_PerceptInfo_h
#define _ROS_hector_worldmodel_msgs_PerceptInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hector_worldmodel_msgs
{

  class PerceptInfo : public ros::Msg
  {
    public:
      typedef const char* _class_id_type;
      _class_id_type class_id;
      typedef float _class_support_type;
      _class_support_type class_support;
      typedef const char* _object_id_type;
      _object_id_type object_id;
      typedef float _object_support_type;
      _object_support_type object_support;
      typedef const char* _name_type;
      _name_type name;

    PerceptInfo():
      class_id(""),
      class_support(0),
      object_id(""),
      object_support(0),
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_class_id = strlen(this->class_id);
      varToArr(outbuffer + offset, length_class_id);
      offset += 4;
      memcpy(outbuffer + offset, this->class_id, length_class_id);
      offset += length_class_id;
      union {
        float real;
        uint32_t base;
      } u_class_support;
      u_class_support.real = this->class_support;
      *(outbuffer + offset + 0) = (u_class_support.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_class_support.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_class_support.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_class_support.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->class_support);
      uint32_t length_object_id = strlen(this->object_id);
      varToArr(outbuffer + offset, length_object_id);
      offset += 4;
      memcpy(outbuffer + offset, this->object_id, length_object_id);
      offset += length_object_id;
      union {
        float real;
        uint32_t base;
      } u_object_support;
      u_object_support.real = this->object_support;
      *(outbuffer + offset + 0) = (u_object_support.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_support.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_support.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_support.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_support);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_class_id;
      arrToVar(length_class_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_class_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_class_id-1]=0;
      this->class_id = (char *)(inbuffer + offset-1);
      offset += length_class_id;
      union {
        float real;
        uint32_t base;
      } u_class_support;
      u_class_support.base = 0;
      u_class_support.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_class_support.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_class_support.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_class_support.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->class_support = u_class_support.real;
      offset += sizeof(this->class_support);
      uint32_t length_object_id;
      arrToVar(length_object_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_id-1]=0;
      this->object_id = (char *)(inbuffer + offset-1);
      offset += length_object_id;
      union {
        float real;
        uint32_t base;
      } u_object_support;
      u_object_support.base = 0;
      u_object_support.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_object_support.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_object_support.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_object_support.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->object_support = u_object_support.real;
      offset += sizeof(this->object_support);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    const char * getType(){ return "hector_worldmodel_msgs/PerceptInfo"; };
    const char * getMD5(){ return "6d276cf0fa6b560cbfd07a3f9eab88b5"; };

  };

}
#endif