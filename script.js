function getDates() {
    var currentDate = prompt("What is today's date in the form MM/DD/YYYY?");
    var birthDate = prompt("What is your birthday in MM/DD/YYYY?");

    var currentDateList = currentDate.split('/');
    var birthDateList = birthDate.split('/');
    var ageInYears = ((currentDateList[2] - birthDateList[2]) + ((currentDateList[0] - birthDateList[0]) / 12) + ((currentDateList[1] - birthDateList[1]) / 365));
    console.log(ageInYears);
    var ageInDays = ageInYears * 365;
    var text = "You are " + ageInDays.toFixed() + " days old."
    document.getElementById('header1').innerHTML = text;

}

function reset() {
    document.getElementById('header1').innerHTML = '';
}