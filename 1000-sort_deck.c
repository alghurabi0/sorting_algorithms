#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * card_compare - Custom comparison function for sorting cards.
 * @card1: Pointer to the first card.
 * @card2: Pointer to the second card.
 *
 * Return: Negative if card1 < card2, 0 if card1 == card2
 */
int card_compare(const void *card1, const void *card2)
{
	const card_t *c1 = *((const card_t **)card1);
	const card_t *c2 = *((const card_t **)card2);
	int value1 = -1, value2 = -1, i;
	static const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

	if (c1->kind < c2->kind)
		return (-1);
	else if (c1->kind > c2->kind)
		return (1);

	for (i = 0; i < 13; i++)
	{
		if (strcmp(c1->value, values[i]) == 0)
			value1 = i;
		if (strcmp(c2->value, values[i]) == 0)
			value2 = i;
	}
	return (value1 - value2);
}

/**
 * sort_deck - Sorts a deck of cards in-place.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	size_t count = 0, i;
	deck_node_t *current = *deck;
	card_t *cards[52];

	while (current)
	{
		cards[count] = (card_t *)current->card;
		current = current->next;
		count++;
	}

	qsort(cards, count, sizeof(card_t *), card_compare);

	current = *deck;
	for (i = 0; i < count; i++)
	{
		current->card = cards[i];
		current = current->next;
	}
}

