<!DOCTYPE html>
<html>

<head>
    <title>Love, Ash</title>
    <link rel="stylesheet" href="style.css">
    <link rel="icon" type="image/png" href="images/61253.png">

    <script src="https://cdnjs.cloudflare.com/ajax/libs/p5.js/0.7.2/p5.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/p5.js/0.7.2/addons/p5.dom.min.js"></script>
    <script src="https://unpkg.com/p5ble@0.0.4/dist/p5.ble.js"></script>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css"
        integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/chart.js@2.8.0"></script>
    <script src="https://unpkg.com/mathjs@6.5.0/dist/math.min.js"></script>
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js"
        integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN"
        crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js"
        integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q"
        crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js"
        integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl"
        crossorigin="anonymous"></script>
</head>

<body>
    <nav class="navbar navbar-expand-lg navbar-dark">
        <img src="https://image.flaticon.com/icons/svg/61/61253.svg" height=50px />
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav navbar-brand">
                <li class="nav-item active">
                    <p class="active display-4">&nbsp;Yours, truly</a>
                </li>
            </ul>
        </div>
    </nav>

    <nav class="navbar fixed-bottom navbar-expand-lg navbar-dark">
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav">
                <li class="nav-item active">
                    <a class="active nav-link lead" href="http://www.ideahacks.la/">IdeaHacks 2021</a>
                </li>
            </ul>
            <ul class="navbar-nav pull-right">
                <li class="nav-item active">
                    <a class="nav-link lead" href="https://ashvin.dev/">A. Nagarajan</a>
                </li>
                <li class="nav-item active">
                    <a class="nav-link lead" href="https://juanbanchs.webflow.io/">J. Banchs</a>
                </li>
            </ul>
        </div>
    </nav>

    <div class="container-fluid vertical-center text-center">
        <div>
            <h1 class="heading display-4 text-center">Send a message to your loved one!</h1>
        </div>
        <br />
        <hr />

        <div class="input-container container-fluid">
            <div class="input-group mb-3 input-group-lg">
                <div class="input-group-prepend">
                    <span class="input-group-text" id="basic-addon1">
                        <3 </span>
                </div>
                <input type="text" id="messageField" class="form-control" placeholder="Type your message"
                    aria-label="Message" aria-describedby="basic-addon1">
            </div>
        </div>


        <div class="d-inline-flex my-auto">
            <p class="large-text lead">Press this button to send your message: &nbsp; </p>

            <button id="send-button" type="button" class="btn btn-secondary" onclick="pushToFirebase()">Send!</button>
        </div>

        <br />
        <hr />

        <!-- Button trigger modal -->
        <div class="d-inline-flex my-auto">
            <p class="large-text lead">View past messages: &nbsp; </p>

            <button type="button" class="btn btn-secondary" onclick="pastMessages()">
                Launch
            </button>
        </div>

        <!-- Modal -->
        <div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel"
            aria-hidden="true">
            <div class="modal-dialog" role="document">
                <div class="modal-content">
                    <div class="modal-header">
                        <h5 class="modal-title" id="exampleModalLabel">Past Messages</h5>
                        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                            <span aria-hidden="true">&times;</span>
                        </button>
                    </div>
                    <div class="modal-body">
                        <div id="modal-body">
                        </div>
                        <div class="modal-footer">
                            <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <script src="scripts.js"></script>

        <!-- The core Firebase JS SDK is always required and must be listed first -->
        <script src="https://www.gstatic.com/firebasejs/8.2.3/firebase-app.js"></script>

        <!-- TODO: Add SDKs for Firebase products that you want to use
     https://firebase.google.com/docs/web/setup#available-libraries -->
        <script src="https://www.gstatic.com/firebasejs/8.2.3/firebase-analytics.js"></script>
        <script src="https://www.gstatic.com/firebasejs/3.1.0/firebase.js"></script>


</body>

</html>