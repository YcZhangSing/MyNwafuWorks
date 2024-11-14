<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<%@ taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<html>
<head>
    <title>登陆系统</title>
    <style>
        .app{
            width: 180px;
            height: 38px;
            margin: 100px auto;
            text-align: center;
            line-height: 38px;
        }

         * {
             margin: 0;
             padding: 0;
         }
        html {
            height: 100%;
        }
        body {
            height: 100%;
        }
        .container {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);
        }
        .login-wrapper {
            background-color: #fff;
            width: 358px;
            height: 588px;
            border-radius: 15px;
            padding: 0 50px;
            position: relative;
            left: 50%;
            top: 50%;
            transform: translate(-50%, -50%);
        }
        .header {
            font-size: 38px;
            font-weight: bold;
            text-align: center;
            line-height: 200px;
        }
        .alert {
            font-size: 28px;
            font-weight: bold;
            text-align: center;
            color: red;
        }
        .input-item {
            display: block;
            width: 100%;
            margin-bottom: 20px;
            border: 0;
            padding: 10px;
            border-bottom: 1px solid rgb(128, 125, 125);
            font-size: 15px;
            outline: none;
        }
        .input-item::placeholder {
            text-transform: uppercase;
        }
        .btn {
            text-align: center;
            padding: 10px;
            width: 100%;
            margin-top: 40px;
            background-image: linear-gradient(to right, #a6c1ee, #fbc2eb);
            color: #fff;
            border: #fbc2eb;

        }
        .msg {
            text-align: center;
            line-height: 88px;
        }
        a {
            text-decoration-line: none;
            color: #abc1ee;
        }

    </style>
    <%
        if(session.getAttribute("err") != null){

    %>
        <script>
            alert('<%=session.getAttribute("err")%>')
        </script>
    <%
        }
        else
        {
            System.out.println("登陆界面获取的err属性"+session.getAttribute("errorr"));
        }
    %>
</head>
<body>
<div class="container">
    <div class="login-wrapper">
        <div class="header">登陆</div>
        <div class="form-wrapper">
    <form action="${pageContext.request.contextPath}/book/allBook" method="post">

        账号：<input type="text" name="name" class="input-item"> <br>
        密码：<input type="password" name="pwd" class="input-item"> <br>
        <input type="submit" value="提交" class="btn">
    </form>
        </div>
    </div>
</div>

</body>
</html>
