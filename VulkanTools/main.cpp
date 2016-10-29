#include <iostream>
#include "MemoryManager.h"
#include "Helper.h"
#include "Label.h"
#include "GUI.h"
#include "Action.h"

using namespace std;

void sfl() {
	printf("slfd\n");
}

int main() {

	//printf("%s\n", helper::flagsToString(VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT|VK_BUFFER_USAGE_INDEX_BUFFER_BIT).c_str());

	CMemoryManager mem_mng;
	mem_mng.allocBuffer(32, VK_BUFFER_USAGE_INDEX_BUFFER_BIT|VK_BUFFER_USAGE_VERTEX_BUFFER_BIT|VK_BUFFER_USAGE_TRANSFER_SRC_BIT|VK_BUFFER_USAGE_TRANSFER_DST_BIT);
	mem_mng.allocBuffer(43, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT);
	mem_mng.displayBuffers();

	Label label("text",offset2D(100,100));

	Action act(sfl);
	act.perform();

	printf("Coucou");
	system("pause");
	return 0;

}