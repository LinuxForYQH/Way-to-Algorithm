#ifndef LEFTIST_TREE_HPP
#define LEFTIST_TREE_HPP 1

#include <algorithm>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

struct LeftistTree;

struct LeftistNode {
    /* 节点下标号 */
	int index;
    /* 节点i的距离为distance[i] */
	int distance;
	LeftistNode *left;
	LeftistNode *right;
	LeftistTree *tree;
};

struct LeftistTree {
	int (*compare)(LeftistNode*, LeftistNode*);
	LeftistNode *root;
	int size;
};

LeftistTree *LeftistTreeNew(int (*compare)(LeftistNode *a, LeftistNode *b))
{
	LeftistTree *t = new LeftistTree();
	if (!t) {
		return NULL;
	}
	t->compare = compare;
	t->root = NULL;
	t->size = 0;
	return t;
}

void LeftistNodeFree(LeftistNode *e)
{
	if (!e)
		return;
	LeftistNodeFree(e->left);
	LeftistNodeFree(e->right);
	delete e;
}

void LeftistTreeFree(LeftistTree *t)
{
	LeftistNodeFree(t->root);
	delete t;
}

LeftistNode *LeftistNodeMerge(LeftistNode *a, LeftistNode *b, LeftistTree *t)
{
	if (!a && !b) {
		return NULL;
	}
	if (!a) {
		b->tree = t;
		return b;
	}
	if (!b) {
		a->tree = t;
		return a;
	}

	int (*compare)(LeftistNode*, LeftistNode*) = t->compare;
	if (compare(a, b) > 0) {
		return LeftistNodeMerge(b, a, t);
	}

	a->right = LeftistNodeMerge(a->right, b, t);
	a->right->tree = t;

	if (!a->left) {
		swap(a->left, a->right);
	} else {
		if (a->left->distance < a->right->distance)
			swap(a->left, a->right);
		a->distance = a->right->distance + 1;
	}

	return a;
}

LeftistTree *LeftistTreeMerge(LeftistTree *a, LeftistTree *b)
{
	a->root = LeftistNodeMerge(a->root, b->root, a);
	b->root = NULL;
	b->size = 0;
	LeftistTreeFree(b);
	return a;
}

int LeftistTreeTop(LeftistTree *t)
{
	return t->root ? t->root->index : -1;
}

int LeftistTreePush(LeftistTree *t, int index)
{
	LeftistNode *e = new LeftistNode();
	if (!e)
		return -1;
	e->distance = 0;
	e->index = index;
	e->left = NULL;
	e->right = NULL;
	e->tree = NULL;

	t->root = LeftistNodeMerge(t->root, e, t);
	t->size += 1;

	return 0;
}

int LeftistTreePop(LeftistTree *t)
{
	if (t->size <= 0)
		return -1;

	LeftistNode *old = t->root;
	t->root = LeftistNodeMerge(t->root->left, t->root->right, t);
	t->size -= 1;

	delete old;

	return 0;
}


#endif