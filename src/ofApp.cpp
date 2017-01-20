#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	mTimecode.setFPS(30);
	currentTime = 0.0f;
	countNumberOfBeat = 0;

	string filename = "tellyourworld.mp4";
	video.load(filename);
	video.play();

	std::string youtube_url = "www.youtube.com/watch?v=PqJNc9KVIZE";
	std::string basic_url = "https://widget.songle.jp/api/v1/song.json?url=" + youtube_url;
	std::string beat_url = "https://widget.songle.jp/api/v1/song/beat.json?url=" + youtube_url;
	
	if (!basic_data.open(basic_url))
	{
		ofLogNotice("ofApp::setup") << "Failed to parse JSON";
	}

	if (!beat_data.open(beat_url))
	{
		ofLogNotice("ofApp::setup") << "Failed to parse JSON";
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	currentTime += ofGetLastFrameTime();
	video.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofBackground(0);
	float nextTime = beat_data["beats"][countNumberOfBeat]["start"].asFloat() / 1000.f;
	if (currentTime > nextTime) {
		countNumberOfBeat++;
		ofBackground(255);
	}

	video.draw(200, 200, video.getWidth()/2, video.getHeight()/2);
	ofSetColor(255);
	ofDrawBitmapString(basic_data["title"].asString(), 20, 20);
	string all_time = mTimecode.timecodeForSeconds((float)basic_data["duration"].asInt() / 1000.f);
	ofDrawBitmapString(mTimecode.timecodeForSeconds(currentTime) + " / " + all_time, 20, 40);
	ofDrawBitmapString("beat : " + beat_data["beats"][countNumberOfBeat]["position"].asString(), 20, 60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'f':
		ofToggleFullscreen();
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
