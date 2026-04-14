document.addEventListener('DOMContentLoaded', function() {
    const video = document.getElementById('myVideo');
    const playPauseBtn = document.getElementById('playPauseBtn');
    const progressBar = document.getElementById('progressBar');
    const timeDisplay = document.getElementById('timeDisplay');
    const muteBtn = document.getElementById('muteBtn');
    const volumeControl = document.getElementById('volumeControl');
    const fullscreenBtn = document.getElementById('fullscreenBtn');

    // Play/Pause toggle
    playPauseBtn.addEventListener('click', function() {
        if (video.paused) {
            video.play();
            playPauseBtn.textContent = '❚❚';
        } else {
            video.pause();
            playPauseBtn.textContent = '▶';
        }
    });

    // Update progress bar as video plays
    video.addEventListener('timeupdate', function() {
        const percentage = (video.currentTime / video.duration) * 100;
        progressBar.value = percentage;
        
        // Update time display
        const currentMinutes = Math.floor(video.currentTime / 60);
        const currentSeconds = Math.floor(video.currentTime % 60).toString().padStart(2, '0');
        const durationMinutes = Math.floor(video.duration / 60);
        const durationSeconds = Math.floor(video.duration % 60).toString().padStart(2, '0');
        
        timeDisplay.textContent = `${currentMinutes}:${currentSeconds} / ${durationMinutes}:${durationSeconds}`;
    });

    // Click on progress bar to seek
    progressBar.addEventListener('input', function() {
        const seekTime = (progressBar.value / 100) * video.duration;
        video.currentTime = seekTime;
    });

    // Volume control
    volumeControl.addEventListener('input', function() {
        video.volume = volumeControl.value;
        
        // Update mute button icon
        if (video.volume === 0) {
            muteBtn.textContent = '🔇';
        } else {
            muteBtn.textContent = '🔊';
        }
    });

    // Mute toggle
    muteBtn.addEventListener('click', function() {
        if (video.volume > 0) {
            video.volume = 0;
            volumeControl.value = 0;
            muteBtn.textContent = '🔇';
        } else {
            video.volume = 1;
            volumeControl.value = 1;
            muteBtn.textContent = '🔊';
        }
    });

    // Fullscreen toggle
    fullscreenBtn.addEventListener('click', function() {
        if (!document.fullscreenElement) {
            video.requestFullscreen().catch(err => {
                console.error(`Error attempting to enable fullscreen: ${err.message}`);
            });
        } else {
            document.exitFullscreen();
        }
    });
});