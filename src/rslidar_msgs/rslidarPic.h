#ifndef _ROS_rslidar_msgs_rslidarPic_h
#define _ROS_rslidar_msgs_rslidarPic_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rslidar_msgs
{

  class rslidarPic : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _col_type;
      _col_type col;
      uint32_t distance_length;
      typedef float _distance_type;
      _distance_type st_distance;
      _distance_type * distance;
      uint32_t intensity_length;
      typedef float _intensity_type;
      _intensity_type st_intensity;
      _intensity_type * intensity;
      uint32_t azimuthforeachP_length;
      typedef float _azimuthforeachP_type;
      _azimuthforeachP_type st_azimuthforeachP;
      _azimuthforeachP_type * azimuthforeachP;

    rslidarPic():
      header(),
      col(0),
      distance_length(0), distance(NULL),
      intensity_length(0), intensity(NULL),
      azimuthforeachP_length(0), azimuthforeachP(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->col >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->col >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->col >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->col >> (8 * 3)) & 0xFF;
      offset += sizeof(this->col);
      *(outbuffer + offset + 0) = (this->distance_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distance_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->distance_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->distance_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_length);
      for( uint32_t i = 0; i < distance_length; i++){
      union {
        float real;
        uint32_t base;
      } u_distancei;
      u_distancei.real = this->distance[i];
      *(outbuffer + offset + 0) = (u_distancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distancei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance[i]);
      }
      *(outbuffer + offset + 0) = (this->intensity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->intensity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->intensity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->intensity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intensity_length);
      for( uint32_t i = 0; i < intensity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_intensityi;
      u_intensityi.real = this->intensity[i];
      *(outbuffer + offset + 0) = (u_intensityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_intensityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_intensityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_intensityi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intensity[i]);
      }
      *(outbuffer + offset + 0) = (this->azimuthforeachP_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->azimuthforeachP_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->azimuthforeachP_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->azimuthforeachP_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->azimuthforeachP_length);
      for( uint32_t i = 0; i < azimuthforeachP_length; i++){
      union {
        float real;
        uint32_t base;
      } u_azimuthforeachPi;
      u_azimuthforeachPi.real = this->azimuthforeachP[i];
      *(outbuffer + offset + 0) = (u_azimuthforeachPi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_azimuthforeachPi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_azimuthforeachPi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_azimuthforeachPi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->azimuthforeachP[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->col =  ((uint32_t) (*(inbuffer + offset)));
      this->col |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->col |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->col |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->col);
      uint32_t distance_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->distance_length);
      if(distance_lengthT > distance_length)
        this->distance = (float*)realloc(this->distance, distance_lengthT * sizeof(float));
      distance_length = distance_lengthT;
      for( uint32_t i = 0; i < distance_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_distance;
      u_st_distance.base = 0;
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_distance = u_st_distance.real;
      offset += sizeof(this->st_distance);
        memcpy( &(this->distance[i]), &(this->st_distance), sizeof(float));
      }
      uint32_t intensity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      intensity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      intensity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      intensity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->intensity_length);
      if(intensity_lengthT > intensity_length)
        this->intensity = (float*)realloc(this->intensity, intensity_lengthT * sizeof(float));
      intensity_length = intensity_lengthT;
      for( uint32_t i = 0; i < intensity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_intensity;
      u_st_intensity.base = 0;
      u_st_intensity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_intensity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_intensity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_intensity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_intensity = u_st_intensity.real;
      offset += sizeof(this->st_intensity);
        memcpy( &(this->intensity[i]), &(this->st_intensity), sizeof(float));
      }
      uint32_t azimuthforeachP_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      azimuthforeachP_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      azimuthforeachP_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      azimuthforeachP_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->azimuthforeachP_length);
      if(azimuthforeachP_lengthT > azimuthforeachP_length)
        this->azimuthforeachP = (float*)realloc(this->azimuthforeachP, azimuthforeachP_lengthT * sizeof(float));
      azimuthforeachP_length = azimuthforeachP_lengthT;
      for( uint32_t i = 0; i < azimuthforeachP_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_azimuthforeachP;
      u_st_azimuthforeachP.base = 0;
      u_st_azimuthforeachP.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_azimuthforeachP.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_azimuthforeachP.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_azimuthforeachP.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_azimuthforeachP = u_st_azimuthforeachP.real;
      offset += sizeof(this->st_azimuthforeachP);
        memcpy( &(this->azimuthforeachP[i]), &(this->st_azimuthforeachP), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "rslidar_msgs/rslidarPic"; };
    const char * getMD5(){ return "f6082ae0a03112c5dd200b5cae6f683d"; };

  };

}
#endif