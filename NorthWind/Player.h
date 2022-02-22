#include "GameObject.h"
#include "InputComponent.h"
#include "PlayerInputComponent.h"

class Player : public GameObject
{
public:
    virtual void Update() override;

private:
    InputComponent * _input;
};