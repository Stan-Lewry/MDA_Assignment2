#include "World.h"

mapTile* World::getMap(){
	return *map;
}

void World::initMap(){

	mapTile grass;
	grass.typeX = 1 * spriteSize;
	grass.typeY = 0;
	grass.blocked = false;
	grass.selected = false;
	grass.moveRange = false;
	grass.attackRange = false;

	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){

			grass.screenX = j * tileSize;
			grass.screenY = i * tileSize;
			grass.worldX = j;
			grass.worldY = i;

			map[i][j] = grass;
		}
	}

	mapTile pathLR;
	pathLR.typeX = 3 * spriteSize;
	pathLR.typeY = 0;
	pathLR.blocked = false;
	pathLR.selected = false;
	pathLR.moveRange = false;
	pathLR.attackRange = false;

	for (int i = 0; i < 4; i++){
		pathLR.screenY = 3 * tileSize;
		pathLR.screenX = i * tileSize;
		pathLR.worldY = 3;
		pathLR.worldX = i;
		map[3][i] = pathLR;
	}

	for (int i = 5; i < 11; i++){
		pathLR.screenY = 7 * tileSize;
		pathLR.screenX = i*tileSize;
		pathLR.worldY = 7;
		pathLR.worldX = i;
		map[7][i] = pathLR;
	}

	for (int i = 12; i < 15; i++){
		pathLR.screenY = 12 * tileSize;
		pathLR.screenX = i * tileSize;
		pathLR.worldY = 12;
		pathLR.worldX = i;
		map[12][i] = pathLR;
	}

	for (int i = 0; i < 5; i++){
		pathLR.screenY = 11 * tileSize;
		pathLR.screenX = i * tileSize;
		pathLR.worldY = 11;
		pathLR.worldX = i;
		map[11][i] = pathLR;
	}

	mapTile path1;
	path1.typeX = 2 * spriteSize;
	path1.typeY = 0;
	path1.blocked = false;
	path1.selected = false;
	path1.attackRange = false;
	path1.moveRange = false;

	for (int i = 4; i < 7; i++){
		path1.screenX = 4 * tileSize;
		path1.screenY = i * tileSize;
		path1.worldX = 4;
		path1.worldY = i;
		map[i][4] = path1;
	}

	for (int i = 8; i < 12; i++){
		path1.screenX = 11 * tileSize;
		path1.screenY = i * tileSize;
		path1.worldX = 11;
		path1.worldY = i;
		map[i][11] = path1;
	}

	for (int i = 12; i < 15; i++){
		path1.screenX = 5 * tileSize;
		path1.screenY = i * tileSize;
		path1.worldX = 5;
		path1.worldY = i;
		map[i][5] = path1;
	}

	mapTile path4;
	path4.typeX = 5 * spriteSize;
	path4.typeY = 0;
	path4.blocked = false;
	path4.selected = false;
	path4.moveRange = false;
	path4.attackRange = false;

	path4.screenX = 4 * tileSize;
	path4.screenY = 3 * tileSize;
	path4.worldX = 4;
	path4.worldY = 3;
	map[3][4] = path4;

	path4.screenX = 11 * tileSize;
	path4.screenY = 7 * tileSize;
	path4.worldX = 11;
	path4.worldY = 7;
	map[7][11] = path4;

	path4.screenX = 5 * tileSize;
	path4.screenY = 11 * tileSize;
	path4.worldX = 5;
	path4.worldY = 11;
	map[11][5] = path4;

	mapTile path6;
	path6.typeX = 7 * spriteSize;
	path6.typeY = 0;
	path6.blocked = false;
	path6.selected = false;
	path6.attackRange = false;
	path6.moveRange = false;

	path6.screenX = 4 * tileSize;
	path6.screenY = 7 * tileSize;
	path6.worldX = 4;
	path6.worldY = 7;
	map[7][4] = path6;

	path6.screenX = 11 * tileSize;
	path6.screenY = 12 * tileSize;
	path6.worldX = 11;
	path6.worldY = 12;
	map[12][11] = path6;

	mapTile wall2;
	wall2.typeX = 2 * spriteSize;
	wall2.typeY = 1 * spriteSize;
	wall2.blocked = true;
	wall2.selected = false;
	wall2.moveRange = false;
	wall2.attackRange = false;

	for (int i = 0; i < 7; i++){
		wall2.screenX = 6 * tileSize;
		wall2.screenY = i * tileSize;
		wall2.worldX = 6;
		wall2.worldY = i;
		map[i][6] = wall2;
	}

	for (int i = 0; i < 2; i++){
		wall2.screenX = 9 * tileSize;
		wall2.screenY = i * tileSize;
		wall2.worldX = 9;
		wall2.worldY = i;
		map[i][9] = wall2;
	}

	for (int i = 3; i < 11; i++){
		wall2.screenX = 13 * tileSize;
		wall2.screenY = i * tileSize;
		wall2.worldX = 13;
		wall2.worldY = i;
		map[i][13] = wall2;
	}
	for (int i = 8; i < 11; i++){
		wall2.screenX = 6 * tileSize;
		wall2.screenY = i * tileSize;
		wall2.worldX = 6;
		wall2.worldY = i;
		map[i][6] = wall2;
	}
	for (int i = 13; i < 15; i++){
		wall2.screenX = 0;
		wall2.screenY = i * tileSize;
		wall2.worldX = 0;
		wall2.worldY = i;
		map[i][0] = wall2;
	}
	for (int i = 13; i < 15; i++){
		wall2.screenX = 4 * tileSize;
		wall2.screenY = i * tileSize;
		wall2.worldX = 4;
		wall2.worldY = i;
		map[i][4] = wall2;
	}

	mapTile wall1;
	wall1.typeX = 1 * spriteSize;
	wall1.typeY = 1 * spriteSize;
	wall1.blocked = true;
	wall1.selected = false;
	wall1.moveRange = false;
	wall1.attackRange = false;

	for (int i = 10; i < 13; i++){
		wall1.screenX = i * tileSize;
		wall1.screenY = 2 * tileSize;
		wall1.worldX = i;
		wall1.worldY = 2;
		map[2][i] = wall1;
	}

	for (int i = 7; i < 11; i++){
		wall1.screenX = i * tileSize;
		wall1.screenY = 11 * tileSize;
		wall1.worldX = i;
		wall1.worldY = 11;
		map[11][i] = wall1;
	}

	wall1.screenX = 1 * tileSize;
	wall1.screenY = 12 * tileSize;
	wall1.worldX = 1;
	wall1.worldY = 12;
	map[12][1] = wall1;

	wall1.screenX = 3 * tileSize;
	wall1.screenY = 12 * tileSize;
	wall1.worldX = 3;
	wall1.worldY = 12;
	map[12][3] = wall1;

	wall1.screenX = 12 * tileSize;
	wall1.screenY = 11 * tileSize;
	wall1.worldX = 12;
	wall1.worldY = 11;
	map[11][12] = wall1;

	mapTile wall4;
	wall4.typeX = 4 * spriteSize;
	wall4.typeY = 1 * spriteSize;
	wall4.blocked = true;
	wall4.selected = false;
	wall4.moveRange = false;
	wall4.attackRange = false;
	wall4.screenX = 0;
	wall4.screenY = 12 * tileSize;
	wall4.worldX = 0;
	wall4.worldY = 12;
	map[12][0] = wall4;

	mapTile wall5;
	wall5.typeX = 5 * spriteSize;
	wall5.typeY = 1 * spriteSize;
	wall5.blocked = true;
	wall5.selected = false;
	wall5.moveRange = false;
	wall5.attackRange = false;

	wall5.screenX = 4 * tileSize;
	wall5.screenY = 12 * tileSize;
	wall5.worldX = 4;
	wall5.worldY = 12;
	map[12][4] = wall5;

	wall5.screenX = 13 * tileSize;
	wall5.screenY = 2 * tileSize;
	wall5.worldX = 13;
	wall5.worldY = 2;
	map[2][13] = wall5;

	mapTile wall3;
	wall3.typeX = 3 * spriteSize;
	wall3.typeY = 1 * spriteSize;
	wall3.blocked = true;
	wall3.selected = false;
	wall3.moveRange = false;
	wall3.attackRange = false;

	wall3.screenX = 6 * tileSize;
	wall3.screenY = 11 * tileSize;
	wall3.worldX = 6;
	wall3.worldY = 11;
	map[11][6] = wall3;

	wall3.screenX = 9 * tileSize;
	wall3.screenY = 2 * tileSize;
	wall3.worldX = 9;
	wall3.worldY = 2;
	map[2][9] = wall3;

	mapTile wall6;
	wall6.typeX = 6 * spriteSize;
	wall6.typeY = 1 * spriteSize;
	wall6.blocked = true;
	wall6.selected = false;
	wall6.moveRange = false;
	wall6.attackRange = false;

	wall6.screenX = 13 * tileSize;
	wall6.screenY = 11 * tileSize;
	wall6.worldX = 13;
	wall6.worldY = 11;
	map[11][13] = wall6;

	mapTile rock;
	rock.typeX = 9 * spriteSize;
	rock.typeY = 0;
	rock.blocked = true;
	rock.selected = false;
	rock.moveRange = false;
	rock.attackRange = false;

	rock.screenX = 3 * tileSize;
	rock.screenY = 1 * tileSize;
	rock.worldX = 3;
	rock.worldY = 1;
	map[1][3] = rock;

	rock.screenX = 13 * tileSize;
	rock.screenY = 13 * tileSize;
	rock.worldX = 13;
	rock.worldY = 13;
	map[13][13] = rock;

	mapTile tree;
	tree.typeX = 8 * spriteSize;
	tree.typeY = 0;
	tree.blocked = true;
	tree.selected = false;
	tree.moveRange = false;
	tree.attackRange = false;

	tree.screenX = 1 * tileSize;
	tree.screenY = 6 * tileSize;
	tree.worldX = 1;
	tree.worldY = 6;
	map[6][1] = tree;

	mapTile grave;
	grave.typeX = 0;
	grave.typeY = 1 * spriteSize;
	grave.blocked = true;
	grave.selected = false;
	grave.moveRange = false;
	grave.attackRange = false;

	grave.screenX = 9 * tileSize;
	grave.screenY = 6 * tileSize;
	grave.worldX = 9;
	grave.worldY = 6;
	map[6][9] = grave;
}

bool World::isTraversable(int x, int y){
	if (x >= 0){
		if (x < mapW){
			if (y >= 0){
				if (y < mapH){
					if (map[y][x].blocked == false){
						return true;
					}
					else return false;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void World::checkMovementRange(int moveDist, int originX, int originY){
	std::vector<mapTile> listA;
	std::vector<mapTile> listB;

	listA.push_back(map[originY][originX]);

	std::cout << "origin: " << originX << ", " << originY << std::endl;

	for (int i = 0; i < moveDist; i++){
		for (int j = 0; j < listA.size(); j++){

			int currentX = listA.at(j).worldX;
			int currentY = listA.at(j).worldY;

			if (isTraversable(currentX, currentY + 1)){
				mapTile southAdj = map[currentY + 1][currentX];
				listB.push_back(southAdj);
				map[southAdj.worldY][southAdj.worldX].moveRange = true;
			}

			if (isTraversable(currentX + 1, currentY)){
				mapTile eastAdj = map[currentY][currentX + 1];
				listB.push_back(eastAdj);
				map[eastAdj.worldY][eastAdj.worldX].moveRange = true;
			}

			if (isTraversable(currentX, currentY - 1)){
				mapTile northAdj = map[currentY - 1][currentX];
				listB.push_back(northAdj);
				map[northAdj.worldY][northAdj.worldX].moveRange = true;
			}

			if (isTraversable(currentX - 1, currentY)){
				mapTile westAdj = map[currentY][currentX - 1];
				listB.push_back(westAdj);
				map[westAdj.worldY][westAdj.worldX].moveRange = true;
			}
		}
		listA = listB;
		listB.clear();
	}
}

void World::checkAttackRange(int attackDist, int originX, int originY){
	std::vector<mapTile> listA;
	std::vector<mapTile> listB;

	listA.push_back(map[originY][originX]);

	std::cout << "origin: " << originX << ", " << originY << std::endl;

	for (int i = 0; i < attackDist; i++){
		for (int j = 0; j < listA.size(); j++){

			int currentX = listA.at(j).worldX;
			int currentY = listA.at(j).worldY;

			if (isTraversable(currentX, currentY + 1)){
				mapTile southAdj = map[currentY + 1][currentX];
				listB.push_back(southAdj);
				map[southAdj.worldY][southAdj.worldX].attackRange = true;
			}

			if (isTraversable(currentX + 1, currentY)){
				mapTile eastAdj = map[currentY][currentX + 1];
				listB.push_back(eastAdj);
				map[eastAdj.worldY][eastAdj.worldX].attackRange = true;
			}

			if (isTraversable(currentX, currentY - 1)){
				mapTile northAdj = map[currentY - 1][currentX];
				listB.push_back(northAdj);
				map[northAdj.worldY][northAdj.worldX].attackRange = true;
			}

			if (isTraversable(currentX - 1, currentY)){
				mapTile westAdj = map[currentY][currentX - 1];
				listB.push_back(westAdj);
				map[westAdj.worldY][westAdj.worldX].attackRange = true;
			}
		}
		listA = listB;
		listB.clear();
	}
}

mapTile World::getTile(int clickX, int clickY, int renderOffsetX, int renderOffsetY){


	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			//map[i][j].selected = false;

			if (clickX >= map[i][j].screenX + renderOffsetX && clickX < map[i][j].screenX + renderOffsetX + tileSize){
				if (clickY >= map[i][j].screenY + renderOffsetY && clickY < map[i][j].screenY + renderOffsetY + tileSize){	
					std::cout << "clicked at: " << j << ", " << i << std::endl;
					
					//map[i][j].selected = true;
					
					//checkMovementRange(5, map[i][j].worldX, map[i][j].worldY);
					
					return map[i][j];
					//map[5][4].selected = true;
				}
			}
		}
	}
	

}

void World::selectTile(int worldX, int worldY){
	map[worldY][worldX].selected = true;
}

void World::clearAll(){
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			map[i][j].selected = false;
			map[i][j].moveRange = false;
			map[i][j].attackRange = false;
		}
	}
}

void World::loadMap(){

}