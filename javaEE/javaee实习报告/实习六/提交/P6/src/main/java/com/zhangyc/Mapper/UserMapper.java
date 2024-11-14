package com.zhangyc.Mapper;

import org.apache.ibatis.annotations.Select;

public interface UserMapper {
    @Select("select passwd from sb.user where user_name=#{name}")
    public String selectUserByName(String name);
}
