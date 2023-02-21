#include <Arduino.h>

const char HTML_INDEX[] PROGMEM = R"=====(
<!DOCTYPE html>
  <html>
  <head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>PC Power Switch</title>"

  <style>
  body {
        background: rgb(0,0,0);
        background: linear-gradient(170deg, rgba(0,0,0,1) 0%, rgba(21,27,31,1) 100%);
        width: 100%;
        height: 99vh;
    }

    /* CSS */
    .button-84 {
        align-items: center;
        background-color: initial;
        background-image: linear-gradient(#464d55, #25292e);
        border-radius: 8px;
        border-width: 0;
        box-shadow: 0 10px 20px rgba(0, 0, 0, .1),0 3px 6px rgba(0, 0, 0, .05);
        box-sizing: border-box;
        color: #fff;
        cursor: pointer;
        display: inline-flex;
        flex-direction: column;
        font-family: expo-brand-demi,system-ui,-apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,"Helvetica Neue",Arial,"Noto Sans",sans-serif,"Apple Color Emoji","Segoe UI Emoji","Segoe UI Symbol","Noto Color Emoji";
        font-size: 18px;
        height: 52px;
        justify-content: center;
        line-height: 1;
        margin: 0;
        outline: none;
        overflow: hidden;
        padding: 0 32px;
        text-align: center;
        text-decoration: none;
        transform: translate3d(0, 0, 0);
        transition: all 150ms;
        vertical-align: baseline;
        white-space: nowrap;
        user-select: none;
        -webkit-user-select: none;
        touch-action: manipulation;
    }

    .button-84:hover {
        box-shadow: rgba(0, 1, 0, .2) 0 2px 8px;
        opacity: .85;
    }

    .button-84:active {
        outline: 0;
    }

    .button-84:focus {
        box-shadow: rgba(0, 0, 0, .5) 0 0 0 3px;
    }

    @media (max-width: 420px) {
    .button-84 {
        height: 48px;
    }
    }

    .main h2:after, 
    h3:after, 
    h4:after {
        position: absolute;
        content: "";
        left: 0;
        top: 0;
        bottom: 0;
        width: 5px;
        border-radius: 2px;
        box-shadow: 
            inset 0 1px 1px rgba(0,0,0,0.5), 
            0 1px 1px rgba(255,255,255,0.3);
    }

    h2:after { background: #0AF; }
    h3:after { background: #3BF; }
    h4:after { background: #6Cf; }

    h1 {
        font-size: 36px;
        line-height: 40px;
        margin: 1em 0 .6em 0;
        font-weight: normal;
        color: white;
        font-family: 'Hammersmith One', sans-serif;
        text-shadow: 0 -1px 0 rgba(0,0,0,0.4);
        position: relative;
        color: #6Cf;
    }

    h2 {
        margin: 1em 0 .6em 0;
        padding: 0 0 0 20px;
        font-weight: normal;
        color: white;
        font-family: 'Hammersmith One', sans-serif;
        text-shadow: 0 -1px 0 rgba(0,0,0,0.4);
        position: relative;
        font-size: 30px;
        line-height: 40px;
    }

    h3 {
        margin: 1em 0 .6em 0;
        padding: 0 0 0 20px;
        font-weight: normal;
        color: white;
        font-family: 'Hammersmith One', sans-serif;
        text-shadow: 0 -1px 0 rgba(0,0,0,0.4);
        position: relative;
        font-size: 24px;
        line-height: 40px;
        font-family: 'Questrial', sans-serif;
    }

    h4 { 
        margin: 1em 0 .6em 0;
        padding: 0 0 0 20px;
        font-weight: normal;
        color: white;
        font-family: 'Hammersmith One', sans-serif;
        text-shadow: 0 -1px 0 rgba(0,0,0,0.4);
        position: relative;
        font-size: 18px;
        line-height: 20px;
        font-family: 'Questrial', sans-serif;
    }

  </style>
  </head>
  <body>
    <div class="continer">
        <h1>PC Power Switch</h1>
        <button class="button-84" role="button" onclick="powerOn()">Power up!</button>
        <button class="button-84" role="button" onclick="longPress()">Hard Reset</button>
        
    </div>
<script>

  // Power on callback
  function powerOn() {
  var xhr = new XMLHttpRequest();

  xhr.onreadystatechange = function() {
    if (xhr.readyState == XMLHttpRequest.DONE) {
        console.log(xhr.responseText);
    }
  }

  xhr.open("GET", "/poweron");
  xhr.send();
  }

  // Long press callback
  function longPress() {
  var xhr = new XMLHttpRequest();

  xhr.onreadystatechange = function() {
    if (xhr.readyState == XMLHttpRequest.DONE) {
        console.log(xhr.responseText);
    }
  }

  xhr.open("GET", "/longpress");
  xhr.send();
  }

  </script>

  </body>
  </html>
)=====";
