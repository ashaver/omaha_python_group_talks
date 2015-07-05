
from zato.server.service import Service
import Simple

class GetClientAnswer(Service):
    def handle(self): # The only method that *has* to be defined. This is the event-triggered entry point.
        self.logger.info('Request Answer: {}'.format(self.request.payload))

       
        response = {}
        q = self.request.payload['question']
        response['question'] = q
        response['answer'] = Simple.missing_answer(q)

        self.logger.info('Response: {}'.format(response))
       
        
        # And return response to the caller
        self.response.payload = response