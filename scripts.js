
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

    let message = document.getElementById("messageField").value;

    console.log(message);

    // Get a reference to the database service
    var database = firebase.database();
    firebase.database().ref('Messages').set({
        [time]: message,
    });
}





