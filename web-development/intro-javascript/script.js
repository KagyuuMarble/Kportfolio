let timer;
let remainingTime = 0;
let isRunning = false;
let interval;

const display = document.getElementById('timerDisplay');
const startButton = document.getElementById('startButton');
const pauseButton = document.getElementById('pauseButton');
const resetButton = document.getElementById('resetButton');
const timeInput = document.getElementById('timeInput');
const setTimeButton = document.getElementById('setTimeButton');


function timeToSeconds(timeString) {
    const [minutes, seconds] = timeString.split(':').map(Number);
    return minutes * 60 + seconds;
}


function formatTime(seconds) {
    const mins = Math.floor(seconds / 60);
    const secs = seconds % 60;
    return `${mins.toString().padStart(2, '0')}:${secs.toString().padStart(2, '0')}`;
}


function updateDisplay() {
    display.textContent = formatTime(remainingTime);
}

function setTimer(newTime) {

    if (!/^\d{1,2}:\d{2}$/.test(newTime)) {
        alert("Please enter time in MM:SS format (e.g., 02:30)");
        return false;
    }
    
    const [minutes, seconds] = newTime.split(':').map(Number);
    
    if (seconds > 59) {
        alert("Seconds must be between 00 and 59");
        return false;
    }
    
    remainingTime = timeToSeconds(newTime);
    updateDisplay();
    return true;
}


function startTimer() {
    if (!isRunning && remainingTime > 0) {
        isRunning = true;
        startButton.disabled = true;
        pauseButton.disabled = false;
        timeInput.disabled = true;
        setTimeButton.disabled = true;
        
        interval = setInterval(function() {
            if (remainingTime > 0) {
                remainingTime--;
                updateDisplay();
            } else {
                clearInterval(interval);
                isRunning = false;
                startButton.disabled = false;
                pauseButton.disabled = true;
                timeInput.disabled = false;
                setTimeButton.disabled = false;
                alert("Timer finished!");
            }
        }, 1000);
    }
}

function pauseTimer() {
    if (isRunning) {
        clearInterval(interval);
        isRunning = false;
        startButton.disabled = false;
        pauseButton.disabled = true;
        timeInput.disabled = false;
        setTimeButton.disabled = false;
    }
}


function resetTimer() {
    clearInterval(interval);
    isRunning = false;
    setTimer(timeInput.value); 
    startButton.disabled = false;
    pauseButton.disabled = true;
    timeInput.disabled = false;
    setTimeButton.disabled = false;
}

setTimer(timeInput.value);

startButton.addEventListener('click', startTimer);
pauseButton.addEventListener('click', pauseTimer);
resetButton.addEventListener('click', resetTimer);
setTimeButton.addEventListener('click', function() {
    if (setTimer(timeInput.value)) {
        pauseTimer(); 
    }
});

timeInput.addEventListener('keypress', function(e) {
    if (e.key === 'Enter') {
        if (setTimer(timeInput.value)) {
            pauseTimer();
        }
    }
});