messages = [];
message = "";

var setup = function () {
    const firebaseConfig = {
        apiKey: "AIzaSyBEbf2QBZ8TW2SZFvgQtDtxqViTeiy5gu0",
        authDomain: "ideahacks-2021.firebaseapp.com",
        databaseURL: "https://ideahacks-2021-default-rtdb.firebaseio.com",
        projectId: "ideahacks-2021",
        storageBucket: "ideahacks-2021.appspot.com",
        messagingSenderId: "755754121321",
        appId: "1:755754121321:web:dc69cf20d696d0acfb4af8",
        measurementId: "G-23RSLKJBF7"
    };
    firebase.initializeApp(firebaseConfig);
}

var pushToFirebase = function () {
    var d = new Date()
    time = d.toUTCString()

    message = document.getElementById("messageField").value;

    console.log(message);

    // Get a reference to the database service
    var database = firebase.database();
    firebase.database().ref('Messages').set({
        [time]: message,
    });

    let button = document.getElementById("send-button");
    setTimeout(() => { button.textContent = "Message has been sent!"; }, 1000);
    setTimeout(() => { button.textContent = "Send!"; }, 6000);

    messages.push(message)
}

var pastMessages = function () {
    $('#myModal').modal()

    $('#myModal').on('shown.bs.modal', function () {
        $('#myInput').trigger('focus')
    })
    console.log(messages.join('\r\n'))
    let modal_body = document.getElementById("modal-body");

    var tag =
        "<div>" +
        message + "<br/>"
    "</div>"
    $(modal_body).append(tag);
}



