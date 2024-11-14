<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>首页</title>
    <style>
        body {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);

        }
        .colortxt{

            background: linear-gradient(to right, red, blue);
            -webkit-background-clip: text;
            color: transparent;

        }

    </style>
</head>
<body>
<div style="
    position: absolute;
    left: 50%;top: 50%;
    transform: translate(-50%,-50%); text-align: center;">
    <h2 class="colortxt">欢迎来到图书管理系统</h2>
    <h3><a href="Controller?action=login" class="colortxt">点此登陆系统</a></h3><br>

</div>
</body>
</html>
