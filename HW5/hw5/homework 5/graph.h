#pragma once
#ifndef graphHeader
#define graphHeader
class graphNode {
public:
	graphNode();
	void connect(graphNode);
	bool haveConnection(graphNode);
private:
	graphNode** nodes;
	graphNode** bfs();
};

#endif
