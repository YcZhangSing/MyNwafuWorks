<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2022/12/19
  Time: 22:38
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!DOCTYPE html>
<html lang="en">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Y.Z.MiniC</title>
    <style>
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
            width: 980px;
            height: 760px;
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
            background: linear-gradient(to right, red, blue);
            -webkit-background-clip: text;
            color: transparent;
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
        .input-item{

            border: solid 1px grey;
            margin: 10px;
        }
        .tishi-item{
            border: solid 1px white;
            margin: 10px;
            font-weight: 500;
            font-style: italic;
            font-size: larger;
        }
        .btn {
            text-align: center;
            padding: 10px;
            width: 100%;
            margin-top: 40px;
            margin-right: 15px;
            margin-left: 15px;
            background-image: linear-gradient(to right, #a6c1ee, #fbc2eb);
            color: black;
            border: #fbc2eb;
            font-weight: 560;
        }
        .msg {
            text-align: center;
            line-height: 88px;
        }
        a {
            text-decoration-line: none;
            color: #abc1ee;
        }
        #Cbox{
            display: flex;
            flex-direction: row;
            justify-content: space-between;
        }
        #tishi{
            display: flex;
            flex-direction: row;
            justify-content: space-between;
        }
        .colortxt{

            background: linear-gradient(to right, red, blue);
            -webkit-background-clip: text;
            color: transparent;

        }
        #btnbox{
            display: flex;
            flex-direction: row;
            justify-content: space-between;
        }
    </style>
</head>
<body>

<div class="container">

    <form class="login-wrapper" name="Cform" id="Cform" method="post" action="/Controller">
        <div class="header">Y.Z.MiniC</div>
        <div id="tishi">
            <div class="form-wrapper">
                <textarea class="tishi-item" cols="50" rows="1">Compiler Input:</textarea>
            </div>
            <div class="form-wrapper">
                <textarea class="tishi-item" cols="50" rows="1">Compiler Output:</textarea>
            </div>
        </div>
        <div id="Cbox">
            <div class="form-wrapper">

                <textarea class="input-item" cols="50" rows="20" name="input" id="input">${input}</textarea>
            </div>
            <div class="form-wrapper">
                <textarea class="input-item" cols="50" rows="20" >${Output}</textarea>
            </div>
        </div>
        <div id="btnbox" >
            <input class="btn" type="button" value="词法分析" onclick="cifa()"/>
            <input class="btn" type="button" value="语法分析" onclick="yufa()"/>
            <input class="btn" type="button" value="语义分析" onclick="yuyi()"/>
            <input class="btn" type="button" value="定义变量" onclick="bl()"/>
        </div>
    </form>
<script>
    function cifa()
    {
        document.Cform.action="Controller?action=cifa";
        document.Cform.submit();
    }
    function yufa()
    {
        document.Cform.action="Controller?action=yufa";
        document.Cform.submit();
    }
    function yuyi()
    {
        document.Cform.action="Controller?action=yuyi";
        document.Cform.submit();
    }
    function bl()
    {
        document.Cform.action="Controller?action=bl";
        document.Cform.submit();
    }
</script>

</div>
</body>
</html>

