#include "Deck.hpp"
#include <cassert>
#include <iostream>
#include <set>

int main(int argc, char* argv[])
{
    // Test other methods than shuffle().

    {
        Deck<int> d;

        d.add(1);
        d.add(2);
        d.add(3);
        assert(d.bottom() == 1);
        assert(d.top() == 3);
        assert(d.draw() == 3);
        assert(d.draw() == 2);
        assert(d.draw() == 1);
    }

    // Deck can contain anything, so Deck can contain a Deck.

    {
        Deck<int> d;
        d.add(1);
        d.add(2);
        d.add(3);

        Deck<Deck<int> > d2;
        d2.add(d);
        d2.add(d);

        Deck<int> d3 = d2.draw();
        assert(d3.draw() == 3 && d3.draw() == 2 && d3.draw() == 1);

        d3 = d2.draw();
        assert(d3.draw() == 3 && d3.draw() == 2 && d3.draw() == 1);
    }

    // Test shuffle. Add numbers 0..99 and check that all of them are found and
    // not in the order.

    {
        Deck<int> d;
        std::set<int> thingsInDeck;

        for (int i = 0; i < 100; i++)
        {
            d.add(i);
            thingsInDeck.insert(i);
        }

        // Shuffle a new deck.

        Deck<int> shuffled = d;
        shuffled.shuffle(123);

        // Test that items are found and not in order.

        bool inOrder = true;

        for (int i = 0; i < 100; i++)
        {
            int card = shuffled.draw();
            if (card != d.draw())
                inOrder = false;

            assert(thingsInDeck.count(card) == 1);
            thingsInDeck.erase(card);
        }

        assert(!inOrder);
        assert(thingsInDeck.empty());
    }

    std::cout << "Tests succeeded. All good, sir!" << std::endl;
}
